import time
from enum import Enum
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray, UInt8, Int32
from sensor_msgs.msg import JointState
import math

from avig_msg.msg import ObjDetect

# ================= CONFIGURACIÓN FÍSICA =================
L1 = 20.0  
L2 = 20.0  
HOME_Q1 = -90.0
HOME_Q2 = 90.0

class Step(Enum):
    INIT_SEQUENCE = -1
    IDLE = 0
    MOVE_TO_PICK_XY = 1
    PICK_DOWN = 2
    GRIP_ON = 3
    MOVE_AVOID_OBSTACLE = 40
    MOVE_TO_PLACE_XY = 4
    PLACE_DOWN = 5
    GRIP_OFF = 6
    WAIT_FOR_VISION = 11  # Nuevo: Pausa para que la visión se estabilice
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
        self.target_orient = 90.0 
        
        self.camera_ready = False
        self.init_calibrated = False
        
        self.cam_q1 = 0.0
        self.cam_q2 = 0.0
        self.pick_arm_deg = 0.0
        self.pick_servo_deg = 90.0

class ScaraTaskFSM(Node):
    def __init__(self):
        super().__init__('maquina_estados_fsm')

        self.robots = {'ra1': RobotContext('ra1'), 'ra2': RobotContext('ra2')}
        
        self.coords = {
            'ra1': {
                'pick': (25.0, 0.0),
                'waypoint': (20.0, -15.0), 
                'boxes': [(4.5, -32.5), (4.5, -22.5), (14.5, -32.5), (14.5, -22.5)],
                'orient_offsets': [0.0, 0.0, 0.0, 0.0] 
            },
            'ra2': {
                'pick': (33.0, 0.0),
                'waypoint': (20.0, -15.0),
                'boxes': [(4.5, -32.5), (4.5, -22.5), (14.5, -32.5), (14.5, -22.5)],
                'orient_offsets': [0.0, 0.0, 0.0, 0.0]
            }
        }

        # Publishers y Subscribers
        self.pub_goals = {}
        self.pub_valve = {}
        self.pub_set_pose = {} 
        self.latest_raw_deg = {'ra1': 0.0, 'ra2': 0.0}

        self.create_subscription(Int32, '/sistema/trigger', self._on_trigger, 10)
        self.create_subscription(ObjDetect, '/detected_objects', self._on_obj_detect, 10)
        self.create_subscription(JointState, '/r1/joint_states', lambda msg: self._on_joint_states('ra1', msg), 10)
        self.create_subscription(JointState, '/r2/joint_states', lambda msg: self._on_joint_states('ra2', msg), 10)

        for ns in self.robots:
            self.pub_goals[ns] = self.create_publisher(Float32MultiArray, f'/{ns}/joint_goals', 10)
            self.pub_valve[ns] = self.create_publisher(UInt8, f'/{ns}/valve_cmd', 10)
            self.pub_set_pose[ns] = self.create_publisher(Float32MultiArray, f'/{ns}/set_pose', 10)
            self.create_subscription(UInt8, f'/{ns}/motion_state', lambda msg, n=ns: self._on_motion_state(n, msg), 10)

        self.timer = self.create_timer(0.1, self._tick)
        self.get_logger().info('FSM: Delay de visión tras soltar activo.')

    def inverse_kinematics(self, x, y):
        try:
            dist_sq = x*x + y*y
            max_reach = (L1 + L2) * 0.99 
            if math.sqrt(dist_sq) > max_reach: return 0.0, 0.0
            D = (dist_sq - L1**2 - L2**2) / (2 * L1 * L2)
            D = max(-1.0, min(1.0, D))
            theta2 = math.atan2(math.sqrt(1 - D**2), D)
            theta1 = math.atan2(y, x) - math.atan2(L2 * math.sin(theta2), L1 + L2 * math.cos(theta2))
            return theta1, theta2
        except: return 0.0, 0.0

    def get_compensated_orient(self, ctx, tx, ty, box_idx=None):
        q1_rad, q2_rad = self.inverse_kinematics(tx, ty)
        place_arm_deg = math.degrees(q1_rad) + math.degrees(q2_rad)
        delta_arm = place_arm_deg - ctx.pick_arm_deg
        
        ideal_servo = ctx.pick_servo_deg - delta_arm
        if box_idx is not None:
            ideal_servo += self.coords[ctx.ns]['orient_offsets'][box_idx]
            
        return ideal_servo % 180.0

    def _on_joint_states(self, ns, msg):
        ctx = self.robots[ns]
        ctx.camera_ready = True 
        prefix = 'r1' if ns == 'ra1' else 'r2'
        for i, name in enumerate(msg.name):
            if name == f'{prefix}_brazo_joint': ctx.cam_q1 = math.degrees(msg.position[i])
            elif name == f'{prefix}_antebrazo_joint': ctx.cam_q2 = math.degrees(msg.position[i])

    def _on_obj_detect(self, msg):
        deg = math.degrees(msg.orient)
        if 30 <= msg.id < 40: self.latest_raw_deg['ra1'] = deg
        elif 40 <= msg.id < 50: self.latest_raw_deg['ra2'] = deg

    def _on_trigger(self, msg):
        target = msg.data
        ns = 'ra1' if target == 1 else 'ra2' if target == 2 else None
        if ns:
            ctx = self.robots[ns]
            if ctx.step in [Step.IDLE, Step.DONE]:
                tx, ty = self.coords[ns]['pick']
                q1_rad, q2_rad = self.inverse_kinematics(tx, ty)
                ctx.pick_arm_deg = math.degrees(q1_rad) + math.degrees(q2_rad)
                obj_deg = self.latest_raw_deg[ns]
                ctx.pick_servo_deg = (90.0 + obj_deg - ctx.pick_arm_deg) % 180.0
                ctx.target_orient = ctx.pick_servo_deg
                ctx.step = Step.MOVE_TO_PICK_XY
                ctx.waiting_done = False; ctx.seen_moving = False

    def _on_motion_state(self, ns, msg):
        ctx = self.robots[ns]
        ctx.last_state = msg.data
        if ctx.waiting_done and ctx.last_state == 1: ctx.seen_moving = True

    def send_robot_cmd_xy(self, ns, x, y, z_up, orient=90.0):
        q1_rad, q2_rad = self.inverse_kinematics(x, y)
        msg = Float32MultiArray()
        msg.data = [float(q1_rad), float(q2_rad), float(1.0 if z_up else 0.0), float(orient)]
        self.pub_goals[ns].publish(msg)

    def send_robot_cmd_raw(self, ns, q1_deg, q2_deg, z_up, orient=90.0):
        msg = Float32MultiArray()
        msg.data = [float(math.radians(q1_deg)), float(math.radians(q2_deg)), float(1.0 if z_up else 0.0), float(orient)]
        self.pub_goals[ns].publish(msg)

    def check_done(self, ns, ctx):
        if not ctx.seen_moving: return (time.time() - ctx.step_start_time) > 3.0
        return ctx.last_state == 0

    def wait_timer(self, ctx, seconds):
        if ctx.wait_until_time is None:
            ctx.wait_until_time = time.time() + seconds
            return False
        if time.time() >= ctx.wait_until_time:
            ctx.wait_until_time = None
            return True
        return False

    def _tick(self):
        for ns, ctx in self.robots.items(): self._run_sequence(ns, ctx)

    def _run_sequence(self, ns, ctx):
        if ctx.step == Step.INIT_SEQUENCE:
            if not ctx.waiting_done:
                if not ctx.camera_ready: return
                # Sincronización inicial
                msg_pose = Float32MultiArray()
                msg_pose.data = [float(math.radians(ctx.cam_q1)), float(math.radians(ctx.cam_q2))]
                self.pub_set_pose[ns].publish(msg_pose)
                self.send_robot_cmd_raw(ns, HOME_Q1, HOME_Q2, z_up=True, orient=90.0)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.IDLE

        elif ctx.step == Step.IDLE: return

        # --- CICLO DE TRABAJO ---
        elif ctx.step == Step.MOVE_TO_PICK_XY:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=True, orient=ctx.target_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.PICK_DOWN; ctx.waiting_done = False

        elif ctx.step == Step.PICK_DOWN:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=False, orient=ctx.target_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, 0.5): ctx.step = Step.GRIP_ON; ctx.waiting_done = False

        elif ctx.step == Step.GRIP_ON:
            self.pub_valve[ns].publish(UInt8(data=0))
            if self.wait_timer(ctx, 0.5): ctx.step = Step.MOVE_AVOID_OBSTACLE; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_AVOID_OBSTACLE:
            if not ctx.waiting_done:
                wx, wy = self.coords[ns]['waypoint']
                comp_orient = self.get_compensated_orient(ctx, wx, wy, box_idx=ctx.target_box_idx)
                self.send_robot_cmd_xy(ns, wx, wy, z_up=True, orient=comp_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.MOVE_TO_PLACE_XY; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_TO_PLACE_XY:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                comp_orient = self.get_compensated_orient(ctx, bx, by, box_idx=ctx.target_box_idx)
                self.send_robot_cmd_xy(ns, bx, by, z_up=True, orient=comp_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.PLACE_DOWN; ctx.waiting_done = False

        elif ctx.step == Step.PLACE_DOWN:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                comp_orient = self.get_compensated_orient(ctx, bx, by, box_idx=ctx.target_box_idx)
                self.send_robot_cmd_xy(ns, bx, by, z_up=False, orient=comp_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, 0.5): ctx.step = Step.GRIP_OFF; ctx.waiting_done = False

        elif ctx.step == Step.GRIP_OFF:
            self.pub_valve[ns].publish(UInt8(data=1)) 
            # Avanzamos al paso de espera para que la cámara calcule con calma
            ctx.step = Step.WAIT_FOR_VISION; ctx.waiting_done = False

        elif ctx.step == Step.WAIT_FOR_VISION:
            # Esperamos 1.5 segundos para que los AprilTags se estabilicen
            if self.wait_timer(ctx, 1.5):
                # Sincronizamos la posición actual detectada por cámara antes de ir a Home
                msg_pose = Float32MultiArray()
                msg_pose.data = [float(math.radians(ctx.cam_q1)), float(math.radians(ctx.cam_q2))]
                self.pub_set_pose[ns].publish(msg_pose)
                
                self.get_logger().info(f"[{ns}] Visión estabilizada. Sincronizando y volviendo a Home.")
                ctx.step = Step.MOVE_HOME; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_HOME:
            if not ctx.waiting_done:
                self.send_robot_cmd_raw(ns, HOME_Q1, HOME_Q2, z_up=True, orient=90.0)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                ctx.step = Step.DONE

        elif ctx.step == Step.DONE:
             ctx.target_box_idx = (ctx.target_box_idx + 1) % 4
             ctx.step = Step.IDLE

def main():
    rclpy.init()
    node = ScaraTaskFSM()
    try: rclpy.spin(node)
    except KeyboardInterrupt: pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__': main()