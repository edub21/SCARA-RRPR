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
    INIT_SEQUENCE = -1   # Home forzado
    
    # --- FASE DE TRABAJO ---
    IDLE = 0
    MOVE_TO_PICK_XY = 1
    PICK_DOWN = 2
    GRIP_ON = 3
    
    MOVE_AVOID_OBSTACLE = 40 # Rodear obstáculo
    MOVE_TO_PLACE_XY = 4     # Ir a caja
    
    PLACE_DOWN = 5
    GRIP_OFF = 6
    MOVE_HOME = 7
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
        # ===============================================

        self.effector_settle_sec = 0.5 

        self.pub_goals = {}
        self.pub_valve = {}
        self.sub_state = {}

        self.create_subscription(Int32, '/sistema/trigger', self._on_trigger, 10)

        for ns in self.robots:
            self.pub_goals[ns] = self.create_publisher(Float32MultiArray, f'/{ns}/joint_goals', 10)
            self.pub_valve[ns] = self.create_publisher(UInt8, f'/{ns}/valve_cmd', 10)
            self.sub_state[ns] = self.create_subscription(
                UInt8, f'/{ns}/motion_state',
                lambda msg, n=ns: self._on_motion_state(n, msg), 10
            )

        self.timer = self.create_timer(0.1, self._tick)
        self.get_logger().info('FSM Listo (Delay 0.5s en bajada). Iniciando Home...')

    # ================= CINEMÁTICA =================
    def inverse_kinematics(self, x, y):
        try:
            dist_sq = x*x + y*y
            max_reach = (L1 + L2) * 0.99 
            if math.sqrt(dist_sq) > max_reach:
                self.get_logger().error(f"Punto ({x}, {y}) fuera de alcance!")
                return 0.0, 0.0

            D = (dist_sq - L1**2 - L2**2) / (2 * L1 * L2)
            if D > 1.0: D = 1.0
            if D < -1.0: D = -1.0
            theta2 = math.atan2(math.sqrt(1 - D**2), D)
            theta1 = math.atan2(y, x) - math.atan2(L2 * math.sin(theta2), L1 + L2 * math.cos(theta2))
            return theta1, theta2
        except:
            return 0.0, 0.0

    # ================= CALLBACKS =================
    def _on_trigger(self, msg):
        target = msg.data
        ns = None
        if target == 1: ns = 'ra1'
        elif target == 2: ns = 'ra2'
        
        if ns:
            ctx = self.robots[ns]
            if ctx.step == Step.IDLE or ctx.step == Step.DONE:
                self.get_logger().info(f"[{ns}] CAJA {ctx.target_box_idx + 1}")
                ctx.step = Step.MOVE_TO_PICK_XY
                ctx.waiting_done = False
                ctx.seen_moving = False
                ctx.target_box_idx = (ctx.target_box_idx + 1) % 4
            elif ctx.step.value < 0:
                 self.get_logger().warn(f"[{ns}] Inicializando...")
            else:
                self.get_logger().warn(f"[{ns}] Ocupado.")

    def _on_motion_state(self, ns, msg):
        ctx = self.robots[ns]
        ctx.last_state = msg.data
        if ctx.waiting_done and ctx.last_state == 1:
            ctx.seen_moving = True

    # ================= COMANDOS =================
    def send_robot_cmd_xy(self, ns, x, y, z_up):
        q1, q2 = self.inverse_kinematics(x, y)
        msg = Float32MultiArray()
        msg.data = [float(q1), float(q2), float(1.0 if z_up else 0.0)]
        self.pub_goals[ns].publish(msg)

    def send_robot_cmd_raw(self, ns, q1_deg, q2_deg, z_up):
        r1 = math.radians(q1_deg)
        r2 = math.radians(q2_deg)
        msg = Float32MultiArray()
        msg.data = [float(r1), float(r2), float(1.0 if z_up else 0.0)]
        self.pub_goals[ns].publish(msg)

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
        
        # --- INICIO (HOME FORZADO) ---
        if ctx.step == Step.INIT_SEQUENCE:
            if not ctx.waiting_done:
                self.pub_valve[ns].publish(UInt8(data=1)) # OFF al inicio
                self.send_robot_cmd_raw(ns, -90.0, 90.0, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                ctx.step = Step.IDLE

        # --- CICLO DE TRABAJO ---
        elif ctx.step == Step.IDLE:
            return

        # 1. PICK (20, 0)
        elif ctx.step == Step.MOVE_TO_PICK_XY:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
                self.get_logger().info(f"[{ns}] 1. Pick ({tx}, {ty})")
            elif self.check_done(ns, ctx):
                ctx.step = Step.PICK_DOWN; ctx.waiting_done = False

        # 2. BAJAR Z
        elif ctx.step == Step.PICK_DOWN:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=False)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            # MODIFICADO: Esperar 0.5s EXTRA después de llegar
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, 0.5): # <--- RETARDO AGREGADO
                    ctx.step = Step.GRIP_ON
                    ctx.waiting_done = False

        # 3. AGARRE (0 = ON)
        elif ctx.step == Step.GRIP_ON:
            self.pub_valve[ns].publish(UInt8(data=0))
            if self.wait_timer(ctx, self.effector_settle_sec):
                ctx.step = Step.MOVE_AVOID_OBSTACLE; ctx.waiting_done = False

        # 4A. RODEAR OBSTACULO
        elif ctx.step == Step.MOVE_AVOID_OBSTACLE:
            if not ctx.waiting_done:
                wx, wy = self.coords[ns]['waypoint']
                self.send_robot_cmd_xy(ns, wx, wy, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
                self.get_logger().info(f"[{ns}] 4a. Esquivando obstáculo via ({wx}, {wy})")
            elif self.check_done(ns, ctx):
                ctx.step = Step.MOVE_TO_PLACE_XY; ctx.waiting_done = False

        # 4B. IR A CAJA
        elif ctx.step == Step.MOVE_TO_PLACE_XY:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                self.send_robot_cmd_xy(ns, bx, by, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
                self.get_logger().info(f"[{ns}] 4b. Caja ({bx}, {by})")
            elif self.check_done(ns, ctx):
                ctx.step = Step.PLACE_DOWN; ctx.waiting_done = False

        # 5. BAJAR EN DESTINO
        elif ctx.step == Step.PLACE_DOWN:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                self.send_robot_cmd_xy(ns, bx, by, z_up=False)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            # MODIFICADO: Esperar 0.5s EXTRA después de llegar
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, 0.5): # <--- RETARDO AGREGADO
                    ctx.step = Step.GRIP_OFF
                    ctx.waiting_done = False

        # 6. SOLTAR (1 = OFF)
        elif ctx.step == Step.GRIP_OFF:
            self.pub_valve[ns].publish(UInt8(data=1)) 
            if self.wait_timer(ctx, self.effector_settle_sec):
                ctx.step = Step.MOVE_HOME; ctx.waiting_done = False

        # 7. HOME
        elif ctx.step == Step.MOVE_HOME:
            if not ctx.waiting_done:
                self.send_robot_cmd_raw(ns, -90.0, 90.0, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
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