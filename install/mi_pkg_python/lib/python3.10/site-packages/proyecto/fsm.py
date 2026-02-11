import time
from enum import Enum
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray, UInt8, Int32
import math

# ================= CONFIGURACIÓN FÍSICA =================
L1 = 20.0  
L2 = 20.0
TIEMPO_SERVO_Z  = 0.5  
TIEMPO_VALVULA  = 0.5  

# ================= CONFIGURACIÓN DE DISPARO (Ajusta aquí los rangos) =================
# Robot 1 (Tags 30-39)
R1_TARGET_X = 44.0
R1_TARGET_Y = 0.0
R1_TOLERANCIA = 5.0  # Rango de detección en cm

# Robot 2 (Tags 40-49)
R2_TARGET_X = 20.0
R2_TARGET_Y = -15.0
R2_TOLERANCIA = 5.0  # Rango de detección en cm

class Step(Enum):
    INIT_SEQUENCE = -1
    IDLE = 0
    MOVE_TO_PICK_XY = 1
    PICK_DOWN = 2
    GRIP_ON = 3
    PICK_UP = 30
    MOVE_AVOID_OBSTACLE = 40
    MOVE_TO_PLACE_XY = 4
    PLACE_DOWN = 5
    GRIP_OFF = 6
    PLACE_UP = 60
    MOVE_HOME = 7
    DONE = 8

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
        self.get_logger().info('Iniciando FSM de Control Dual...')

        self.robots = {'ra1': RobotContext('ra1'), 'ra2': RobotContext('ra2')}
        
        # Coordenadas de trabajo (Pick y Depósito)
        self.coords = {
            'ra1': {
                'pick': (20.0, 0.0),
                'waypoint': (20.0, -15.0), 
                'boxes': [(-10.0, -25.0), (-10.0, -35.0), (0.0, -25.0), (0.0, -35.0)]
            },
            'ra2': {
                'pick': (20.0, 0.0),
                'waypoint': (20.0, -15.0),
                'boxes': [(-10.0, -25.0), (-10.0, -35.0), (0.0, -25.0), (0.0, -35.0)]
            }
        }

        self.pub_goals = {}
        self.pub_valve = {}

        # Suscripción a visión
        self.create_subscription(Float32MultiArray, '/detected_objects', self._on_object_detection, 10)
        self.create_subscription(Int32, '/sistema/trigger', self._on_trigger, 10)

        for ns in self.robots:
            self.pub_goals[ns] = self.create_publisher(Float32MultiArray, f'/{ns}/joint_goals', 10)
            self.pub_valve[ns] = self.create_publisher(UInt8, f'/{ns}/valve_cmd', 10)
            # Suscriptor al estado de movimiento (0=Parado, 1=Moviendo)
            self.create_subscription(UInt8, f'/{ns}/motion_state', 
                                     lambda msg, n=ns: self._on_motion_state(n, msg), 10)

        self.timer = self.create_timer(0.1, self._tick)
        self.get_logger().info('FSM Lista. Robots moviendo a Home...')

    # --- LÓGICA DE DISPARO ---
    def _on_object_detection(self, msg):
        if len(msg.data) < 3: return
        tag_id = int(msg.data[0])
        x_obj, y_obj = msg.data[1], msg.data[2]

        if 30 <= tag_id <= 39: # Robot 1
            dist = math.sqrt((x_obj - R1_TARGET_X)**2 + (y_obj - R1_TARGET_Y)**2)
            if dist <= R1_TOLERANCIA: self.trigger_robot('ra1')
        elif 40 <= tag_id <= 49: # Robot 2
            dist = math.sqrt((x_obj - R2_TARGET_X)**2 + (y_obj - R2_TARGET_Y)**2)
            if dist <= R2_TOLERANCIA: self.trigger_robot('ra2')

    def trigger_robot(self, ns):
        ctx = self.robots[ns]
        if ctx.step == Step.IDLE or ctx.step == Step.DONE:
            ctx.step = Step.MOVE_TO_PICK_XY
            ctx.waiting_done = False
            ctx.seen_moving = False
            ctx.target_box_idx = (ctx.target_box_idx + 1) % 4
            self.get_logger().info(f'[{ns}] Disparo automático activado!')

    def _on_motion_state(self, ns, msg):
        ctx = self.robots[ns]
        ctx.last_state = msg.data
        if ctx.waiting_done and ctx.last_state == 1:
            ctx.seen_moving = True

    # --- COMANDOS Y CINEMÁTICA ---
    def inverse_kinematics(self, x, y):
        try:
            dist_sq = x*x + y*y
            D = (dist_sq - L1**2 - L2**2) / (2 * L1 * L2)
            D = max(-1.0, min(1.0, D))
            theta2 = math.atan2(math.sqrt(1 - D**2), D)
            theta1 = math.atan2(y, x) - math.atan2(L2 * math.sin(theta2), L1 + L2 * math.cos(theta2))
            return theta1, theta2
        except: return 0.0, 0.0

    def send_robot_cmd_raw(self, ns, q1_deg, q2_deg, z_up):
        msg = Float32MultiArray()
        msg.data = [float(math.radians(q1_deg)), float(math.radians(q2_deg)), float(1.0 if z_up else 0.0)]
        self.pub_goals[ns].publish(msg)

    def send_robot_cmd_xy(self, ns, x, y, z_up):
        q1, q2 = self.inverse_kinematics(x, y)
        msg = Float32MultiArray()
        msg.data = [float(q1), float(q2), float(1.0 if z_up else 0.0)]
        self.pub_goals[ns].publish(msg)

    def check_done(self, ns, ctx):
        # Si se movió y paró, o si han pasado 4 segundos de seguridad
        if ctx.seen_moving and ctx.last_state == 0: return True
        if (time.time() - ctx.step_start_time) > 4.0: return True
        return False

    def wait_timer(self, ctx, seconds):
        if ctx.wait_until_time is None:
            ctx.wait_until_time = time.time() + seconds
            return False
        if time.time() >= ctx.wait_until_time:
            ctx.wait_until_time = None
            return True
        return False

    def _tick(self):
        for ns, ctx in self.robots.items():
            self._run_sequence(ns, ctx)

    # --- MÁQUINA DE ESTADOS ---
    def _run_sequence(self, ns, ctx):
        if ctx.step == Step.INIT_SEQUENCE:
            if not ctx.waiting_done:
                self.pub_valve[ns].publish(UInt8(data=1)) # Válvula OFF
                # Ambos robots a -90, 90
                self.send_robot_cmd_raw(ns, -90.0, 90.0, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                ctx.step = Step.IDLE # Detención total aquí

        elif ctx.step == Step.IDLE: return

        elif ctx.step == Step.MOVE_TO_PICK_XY:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.PICK_DOWN; ctx.waiting_done = False

        elif ctx.step == Step.PICK_DOWN:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=False) 
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, TIEMPO_SERVO_Z): ctx.step = Step.GRIP_ON; ctx.waiting_done = False

        elif ctx.step == Step.GRIP_ON:
            self.pub_valve[ns].publish(UInt8(data=0)) # ON
            if self.wait_timer(ctx, TIEMPO_VALVULA): ctx.step = Step.PICK_UP; ctx.waiting_done = False

        elif ctx.step == Step.PICK_UP:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, TIEMPO_SERVO_Z): ctx.step = Step.MOVE_AVOID_OBSTACLE; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_AVOID_OBSTACLE:
            if not ctx.waiting_done:
                wx, wy = self.coords[ns]['waypoint']
                self.send_robot_cmd_xy(ns, wx, wy, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.MOVE_TO_PLACE_XY; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_TO_PLACE_XY:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                self.send_robot_cmd_xy(ns, bx, by, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.PLACE_DOWN; ctx.waiting_done = False

        elif ctx.step == Step.PLACE_DOWN:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                self.send_robot_cmd_xy(ns, bx, by, z_up=False)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, TIEMPO_SERVO_Z): ctx.step = Step.GRIP_OFF; ctx.waiting_done = False

        elif ctx.step == Step.GRIP_OFF:
            self.pub_valve[ns].publish(UInt8(data=1)) # OFF
            if self.wait_timer(ctx, TIEMPO_VALVULA): ctx.step = Step.PLACE_UP; ctx.waiting_done = False

        elif ctx.step == Step.PLACE_UP:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                self.send_robot_cmd_xy(ns, bx, by, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, TIEMPO_SERVO_Z): ctx.step = Step.MOVE_HOME; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_HOME:
            if not ctx.waiting_done:
                self.send_robot_cmd_raw(ns, -90.0, 90.0, z_up=True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.DONE

        elif ctx.step == Step.DONE: ctx.step = Step.IDLE

    def _on_trigger(self, msg): # Trigger manual por si acaso
        if msg.data == 1: self.trigger_robot('ra1')
        elif msg.data == 2: self.trigger_robot('ra2')

def main(args=None):
    rclpy.init(args=args)
    node = ScaraTaskFSM()
    try: rclpy.spin(node)
    except KeyboardInterrupt: pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()