import time
from enum import Enum
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray, UInt8, Int32
import math

# ================= CONFIGURACIÓN FÍSICA =================
L1 = 20.0  
L2 = 20.0  

class Step(Enum):
    # --- FASE DE INICIO ---
    INIT_SEQUENCE = -1   
    
    # --- FASE DE TRABAJO ---
    IDLE = 0
    MOVE_TO_PICK_XY = 1
    PICK_DOWN = 2
    GRIP_ON = 3
    
    MOVE_AVOID_OBSTACLE = 40 
    MOVE_TO_PLACE_XY = 4     # <--- Aquí aplicaremos la corrección "Paralelo X"
    
    PLACE_DOWN = 5
    GRIP_OFF = 6
    MOVE_HOME = 7            # <--- Aquí forzaremos 90 grados
    DONE = 8
    ERROR = 99

class RobotContext:
    def __init__(self, ns: str):
        self.ns = ns
        self.step = Step.INIT_SEQUENCE 
        self.last_state = 0
        self.waiting_done = False
        self.step_start_time = 0.0
        self.target_box_idx = 0
        self.wait_until_time = None
        self.seen_moving = False

class ScaraTaskFSM(Node):
    def __init__(self):
        super().__init__('scara_task_fsm')

        self.robots = {'ra1': RobotContext('ra1'), 'ra2': RobotContext('ra2')}
        
        # ================= COORDENADAS =================
        self.coords = {
            'ra1': {
                'home_coords': (20.5, 22.5), 
                'pick': (20.0, 0.0),
                'waypoint': (20.0, -15.0), 
                'boxes': [(-10.0, -25.0), (-10.0, -35.0), (0.0, -25.0), (0.0, -35.0)]
            },
            'ra2': {
                'home_coords': (20.5, 22.5),
                'pick': (20.0, 0.0),
                'waypoint': (20.0, -15.0),
                'boxes': [(-10.0, -25.0), (-10.0, -35.0), (0.0, -25.0), (0.0, -35.0)]
            }
        }
        
        self.effector_settle_sec = 0.5 

        self.pub_goals = {}
        self.pub_valve = {}
        self.sub_state = {}

        self.create_subscription(Int32, '/sistema/trigger', self._on_trigger, 10)

        for ns in self.robots:
            # [q1, q2, z_up, q_orient]
            self.pub_goals[ns] = self.create_publisher(Float32MultiArray, f'/{ns}/joint_goals', 10)
            self.pub_valve[ns] = self.create_publisher(UInt8, f'/{ns}/valve_cmd', 10)
            self.sub_state[ns] = self.create_subscription(
                UInt8, f'/{ns}/motion_state',
                lambda msg, n=ns: self._on_motion_state(n, msg), 10
            )

        self.timer = self.create_timer(0.1, self._tick)
        self.get_logger().info('FSM Listo: Home=90deg | Place=Paralelo X')

    # ================= CINEMÁTICA =================
    def inverse_kinematics(self, x, y):
        try:
            dist_sq = x*x + y*y
            max_reach = (L1 + L2) * 0.99 
            if math.sqrt(dist_sq) > max_reach:
                return 0.0, 0.0 # Fuera de rango

            D = (dist_sq - L1**2 - L2**2) / (2 * L1 * L2)
            if D > 1.0: D = 1.0
            if D < -1.0: D = -1.0
            theta2 = math.atan2(math.sqrt(1 - D**2), D)
            theta1 = math.atan2(y, x) - math.atan2(L2 * math.sin(theta2), L1 + L2 * math.cos(theta2))
            return theta1, theta2
        except:
            return 0.0, 0.0

    # ================= CÁLCULO DE ORIENTACIÓN "PARALELO AL EJE X" =================
    def calculate_parallel_orientation(self, q1_rad, q2_rad):
        """
        Para que la herramienta quede paralela al eje X global, el servo debe girar
        en sentido contrario a la suma de los ángulos del brazo.
        Centro servo = 90 grados.
        """
        total_arm_angle_deg = math.degrees(q1_rad + q2_rad)
        servo_angle = 90.0 - total_arm_angle_deg
        return max(0.0, min(180.0, servo_angle))

    # ================= COMANDOS =================
    def send_robot_cmd_xy(self, ns, x, y, z_up):
        """
        Calcula IK y ORIENTACIÓN AUTOMÁTICA (Paralelo a X).
        Se usa para Pick y Place.
        """
        q1, q2 = self.inverse_kinematics(x, y)
        q_orient = self.calculate_parallel_orientation(q1, q2) # <--- Corrección Paralelo
        
        msg = Float32MultiArray()
        msg.data = [float(q1), float(q2), float(1.0 if z_up else 0.0), float(q_orient)]
        self.pub_goals[ns].publish(msg)

    def send_robot_cmd_manual_orient(self, ns, x, y, z_up, fixed_orient):
        """
        Calcula IK pero FUERZA la orientación a un valor fijo (ej. 90).
        Se usa para HOME.
        """
        q1, q2 = self.inverse_kinematics(x, y)
        
        msg = Float32MultiArray()
        msg.data = [float(q1), float(q2), float(1.0 if z_up else 0.0), float(fixed_orient)]
        self.pub_goals[ns].publish(msg)
        
    def send_robot_cmd_raw(self, ns, q1_deg, q2_deg, z_up, orient_deg):
        r1 = math.radians(q1_deg)
        r2 = math.radians(q2_deg)
        msg = Float32MultiArray()
        msg.data = [float(r1), float(r2), float(1.0 if z_up else 0.0), float(orient_deg)]
        self.pub_goals[ns].publish(msg)

    # ================= UTILIDADES =================
    def check_done(self, ns, ctx):
        if not ctx.seen_moving:
            if (time.time() - ctx.step_start_time) > 3.0: 
                return True 
            return False
        return ctx.last_state == 0

    def wait_timer(self, ctx, seconds):
        if ctx.wait_until_time is None:
            ctx.wait_until_time = time.time() + seconds
            return False
        if time.time() >= ctx.wait_until_time:
            ctx.wait_until_time = None
            return True
        return False

    # ================= LÓGICA PRINCIPAL =================
    def _tick(self):
        for ns, ctx in self.robots.items():
            self._run_sequence(ns, ctx)

    def _run_sequence(self, ns, ctx):
        
        # --- INICIO (Home 90 Grados) ---
        if ctx.step == Step.INIT_SEQUENCE:
            if not ctx.waiting_done:
                self.pub_valve[ns].publish(UInt8(data=1)) 
                # Raw a 90/-90 y Orientacion 90
                self.send_robot_cmd_raw(ns, -90.0, 90.0, z_up=True, orient_deg=90.0)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                ctx.step = Step.IDLE

        elif ctx.step == Step.IDLE:
            return

        # 1. PICK (También usamos corrección paralela para agarrar bien)
        elif ctx.step == Step.MOVE_TO_PICK_XY:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=True) # <--- Calcula orientación
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
                self.get_logger().info(f"[{ns}] 1. Pick...")
            elif self.check_done(ns, ctx):
                ctx.step = Step.PICK_DOWN; ctx.waiting_done = False

        # 2. BAJAR Z
        elif ctx.step == Step.PICK_DOWN:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=False) # Mantiene orientación
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, 0.5):
                    ctx.step = Step.GRIP_ON; ctx.waiting_done = False

        # 3. AGARRE
        elif ctx.step == Step.GRIP_ON:
            self.pub_valve[ns].publish(UInt8(data=0))
            if self.wait_timer(ctx, self.effector_settle_sec):
                ctx.step = Step.MOVE_AVOID_OBSTACLE; ctx.waiting_done = False

        # 4A. RODEAR OBSTACULO
        elif ctx.step == Step.MOVE_AVOID_OBSTACLE:
            if not ctx.waiting_done:
                wx, wy = self.coords[ns]['waypoint']
                self.send_robot_cmd_xy(ns, wx, wy, z_up=True) # <--- Sigue corrigiendo
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                ctx.step = Step.MOVE_TO_PLACE_XY; ctx.waiting_done = False

        # 4B. IR A CAJA (AQUI QUEREMOS PARALELO EJE X)
        elif ctx.step == Step.MOVE_TO_PLACE_XY:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                
                # Usamos send_robot_cmd_xy que incluye calculate_parallel_orientation
                self.send_robot_cmd_xy(ns, bx, by, z_up=True) 
                
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
                self.get_logger().info(f"[{ns}] 4b. Place (Orientacion Paralela X)")
            elif self.check_done(ns, ctx):
                ctx.step = Step.PLACE_DOWN; ctx.waiting_done = False

        # 5. BAJAR EN DESTINO
        elif ctx.step == Step.PLACE_DOWN:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                self.send_robot_cmd_xy(ns, bx, by, z_up=False) # Mantiene corrección
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, 0.5): 
                    ctx.step = Step.GRIP_OFF; ctx.waiting_done = False

        # 6. SOLTAR
        elif ctx.step == Step.GRIP_OFF:
            self.pub_valve[ns].publish(UInt8(data=1)) 
            if self.wait_timer(ctx, self.effector_settle_sec):
                ctx.step = Step.MOVE_HOME; ctx.waiting_done = False

        # 7. HOME (AQUI FORZAMOS 90 GRADOS)
        elif ctx.step == Step.MOVE_HOME:
            if not ctx.waiting_done:
                hx, hy = self.coords[ns]['home_coords']
                
                # Usamos la funcion MANUAL que fuerza el angulo a 90.0
                self.send_robot_cmd_manual_orient(ns, hx, hy, z_up=True, fixed_orient=90.0)
                
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
                self.get_logger().info(f"[{ns}] 7. Home (Orientacion Reset 90)")
            elif self.check_done(ns, ctx):
                ctx.step = Step.DONE

        elif ctx.step == Step.DONE:
             ctx.step = Step.IDLE

def main():
    rclpy.init()
    node = ScaraTaskFSM()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt: pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()