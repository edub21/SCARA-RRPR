import time
from enum import Enum
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray, UInt8, Int32
from sensor_msgs.msg import JointState
import math

from avig_msg.msg import ObjDetect

L1 = 20.0  
L2 = 20.0  

DELAY_BAJAR_CAJA = 1.5      
DELAY_SOLTAR_AIRE = 0.6     
DELAY_SUCCION_ON = 0.6      
TIMEOUT_MOVIMIENTO = 2.5    
TIMEOUT_HOME = 2.0          
OFFSET_WAYPOINT_PRECISION = 15.0 
MAX_RETRIES_HOME = 2

class Step(Enum):
    INIT_SEQUENCE = -1
    IDLE = 0
    MOVE_APPROACH_PICK = 1      
    MOVE_TO_PICK_XY = 2
    PICK_DOWN = 3
    GRIP_ON = 4
    PICK_UP = 5                 
    MOVE_VISION_HOME_WAYPOINT = 6  
    VERIFY_HOME_POSITION = 6.5  
    CALIBRATE_WITH_TAGS = 7     
    MOVE_TO_PLACE_JOINTS = 8    
    ROTATE_BEFORE_DROP = 9
    PRE_PLACE_PRECISION = 9.5   
    PLACE_DOWN = 10
    GRIP_OFF = 11
    PLACE_UP = 12               
    MOVE_HOME = 13              
    DONE = 14

class RobotContext:
    def __init__(self, ns: str):
        self.ns = ns
        self.active_coord_key = ns
        self.step = Step.INIT_SEQUENCE 
        self.last_state = 0
        self.waiting_done = False
        self.step_start_time = 0.0
        self.seen_moving = False
        self.target_orient = 90.0 
        self.picked_error_deg = 0.0
        self.camera_ready = False
        self.init_calibrated = False
        self.cam_q1 = -90.0
        self.cam_q2 = 90.0
        self.cmd_q1 = -90.0
        self.cmd_q2 = 90.0
        self.home_retries = 0

class ScaraTaskFSM(Node):
    def __init__(self):
        super().__init__('scara_task_fsm')
        self.robots = {'ra1': RobotContext('ra1'), 'ra2': RobotContext('ra2')}
        
        self.coords = {
            'ra1': {# verdes
                'home_coords': (20.0, 20.0), 
                'approach_pick': (30.0, 10.0), 
                'pick': (30.0, 0.0),
                'boxes': [
                    (0.0 - 10.5, -26.5 - 5.0 , 90.0-25),   
                    (0.0 - 10.0, -25.5 + 3.0 , 80.0),  
                    (0.0 + 2.5, -27.5 - 7.5  , 90.0), 
                    (0.0 + 8.0, -27.5 + 5.0  , 2.0) 
                ]
            },
            'ra12': { # rojas 
                'home_coords': (20.0, 20.0), 
                'approach_pick': (30.0, 10.0), 
                'pick': (30.0, 0.0),
                'boxes': [
                    (-30.0 , -20 , 90.0-25),   
                    (-30.0 , -20 , 80.0),  
                    (-30.0 , -20  , 90.0), 
                    (-30.0 , -20   , 2.0) 
                ]
            },
            'ra2': {
                'home_coords': (20.0, 20.0),
                'approach_pick': (29.0, 5.0),
                'pick': (29.0, 0.0),
                'boxes': [
                    (2.0, -28.0, 55.0), 
                    (2.0, -28.0, 55.0), 
                    (2.0, -28.0, 55.0), 
                    (2.0, -28.0, 55.0)
                ]
            }
        }
        
        self.box_indices = {'ra1': 0, 'ra12': 0, 'ra2': 0}
        
        for key in self.coords:
            self.coords[key]['boxes_joints'] = []
            for (x, y, off) in self.coords[key]['boxes']:
                q1, q2 = self.inverse_kinematics(x, y)
                self.coords[key]['boxes_joints'].append((q1, q2, off))

        self.latest_raw_deg = {'r1_tag30': 0.0, 'r1_tag40': 0.0, 'r2_tag30': 0.0, 'r2_tag40': 0.0}
        
        self.pub_goals = {}
        self.pub_valve = {}
        self.pub_set_pose = {} 
        self.sub_state = {}

        for ns in self.robots:
            self.pub_goals[ns] = self.create_publisher(Float32MultiArray, f'/{ns}/joint_goals', 10)
            self.pub_valve[ns] = self.create_publisher(UInt8, f'/{ns}/valve_cmd', 10)
            self.pub_set_pose[ns] = self.create_publisher(Float32MultiArray, f'/{ns}/set_pose', 10) 
            self.sub_state[ns] = self.create_subscription(UInt8, f'/{ns}/motion_state', 
                                                         lambda msg, n=ns: self._on_motion_state(n, msg), 10)
            self.pub_valve[ns].publish(UInt8(data=1))

        self.create_subscription(Int32, '/sistema/trigger', self._on_trigger, 10)
        self.create_subscription(ObjDetect, '/detected_objects', self._on_obj_detect, 10)
        self.create_subscription(JointState, '/r1/joint_states', lambda msg: self._on_joint_states('ra1', msg), 10)
        self.create_subscription(JointState, '/r2/joint_states', lambda msg: self._on_joint_states('ra2', msg), 10)

        self.timer = self.create_timer(0.1, self._tick)

    def inverse_kinematics(self, x, y):
        dist_sq = x*x + y*y
        D = (dist_sq - L1**2 - L2**2) / (2 * L1 * L2)
        D = max(-1.0, min(1.0, D))
        theta2 = math.atan2(math.sqrt(1 - D**2), D)
        theta1 = math.atan2(y, x) - math.atan2(L2 * math.sin(theta2), L1 + L2 * math.cos(theta2))
        return math.degrees(theta1), math.degrees(theta2)

    def get_servo_angle(self, q1, q2, target_abs=90.0):
        return (target_abs - (q1 + q2)) % 180.0

    def send_cmd(self, ns, q1, q2, z_up, orient=90.0):
        self.robots[ns].cmd_q1, self.robots[ns].cmd_q2 = q1, q2
        msg = Float32MultiArray()
        msg.data = [float(math.radians(q1)), float(math.radians(q2)), float(1.0 if z_up else 0.0), float(orient)]
        self.pub_goals[ns].publish(msg)

    def _on_joint_states(self, ns, msg):
        ctx = self.robots[ns]
        ctx.camera_ready = True 
        prefix = 'r1' if ns == 'ra1' else 'r2'
        for i, name in enumerate(msg.name):
            if name == f'{prefix}_brazo_joint': ctx.cam_q1 = math.degrees(msg.position[i])
            elif name == f'{prefix}_antebrazo_joint': ctx.cam_q2 = math.degrees(msg.position[i])

    def _on_obj_detect(self, msg):
        base_id = msg.id // 100
        tag_id = msg.id % 100
        
        target = f'r{base_id}_tag{"30" if 30 <= tag_id < 40 else "40"}'
        self.latest_raw_deg[target] = math.degrees(msg.orient)

    def _on_trigger(self, msg):
        base_id = msg.data // 100
        tag_id = msg.data % 100
        
        ns = 'ra1' if base_id == 1 else 'ra2' if base_id == 2 else None
        if not ns: return
        
        ctx = self.robots[ns]
        if ctx.step == Step.IDLE:
            if base_id == 1:
                coord_key = 'ra12' if 30 <= tag_id < 40 else 'ra1'
            else:
                coord_key = 'ra12' if 30 <= tag_id < 40 else 'ra2'

            ctx.active_coord_key = coord_key
            tx, ty = self.coords[coord_key]['pick']
            q1, q2 = self.inverse_kinematics(tx, ty)
            
            vision_target = f'r{base_id}_tag{"30" if 30 <= tag_id < 40 else "40"}'
            ctx.picked_error_deg = self.latest_raw_deg.get(vision_target, 0.0)
            ctx.target_orient = self.get_servo_angle(q1, q2, 90.0 + ctx.picked_error_deg)
            
            ctx.step = Step.MOVE_APPROACH_PICK
            ctx.waiting_done = False

    def _on_motion_state(self, ns, msg):
        ctx = self.robots[ns]
        ctx.last_state = msg.data
        if ctx.waiting_done and ctx.last_state == 1: ctx.seen_moving = True

    def check_done(self, ns, ctx, is_home=False):
        timeout = TIMEOUT_HOME if is_home else TIMEOUT_MOVIMIENTO
        if not ctx.seen_moving: 
            return (time.time() - ctx.step_start_time) > timeout
        return ctx.last_state == 0

    def _tick(self):
        for ns, ctx in self.robots.items():
            self._run_sequence(ns, ctx)

    def _run_sequence(self, ns, ctx):
        if ctx.step == Step.INIT_SEQUENCE:
            if not ctx.waiting_done:
                if not ctx.camera_ready: return 
                if not ctx.init_calibrated:
                    msg = Float32MultiArray(); msg.data = [math.radians(ctx.cam_q1), math.radians(ctx.cam_q2)]
                    self.pub_set_pose[ns].publish(msg)
                    ctx.init_calibrated = True; return 
                self.send_cmd(ns, -90.0, 90.0, True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx, is_home=True):
                if ctx.last_state == 0:
                    ctx.step = Step.IDLE; ctx.waiting_done = False; ctx.home_retries = 0
                else:
                    if ctx.home_retries < MAX_RETRIES_HOME:
                        ctx.home_retries += 1
                        ctx.waiting_done = False
                    else:
                        ctx.step = Step.IDLE

        elif ctx.step == Step.MOVE_APPROACH_PICK:
            if not ctx.waiting_done:
                q1, q2 = self.inverse_kinematics(*self.coords[ctx.active_coord_key]['approach_pick'])
                self.send_cmd(ns, q1, q2, True, ctx.target_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.MOVE_TO_PICK_XY; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_TO_PICK_XY:
            if not ctx.waiting_done:
                q1, q2 = self.inverse_kinematics(*self.coords[ctx.active_coord_key]['pick'])
                self.send_cmd(ns, q1, q2, True, ctx.target_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.PICK_DOWN; ctx.waiting_done = False

        elif ctx.step == Step.PICK_DOWN:
            if not ctx.waiting_done:
                q1, q2 = self.inverse_kinematics(*self.coords[ctx.active_coord_key]['pick'])
                self.send_cmd(ns, q1, q2, False, ctx.target_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): 
                ctx.step = Step.GRIP_ON; ctx.waiting_done = False; ctx.step_start_time = time.time()

        elif ctx.step == Step.GRIP_ON:
            self.pub_valve[ns].publish(UInt8(data=0))
            if (time.time() - ctx.step_start_time) > DELAY_SUCCION_ON: 
                ctx.step = Step.PICK_UP; ctx.waiting_done = False

        elif ctx.step == Step.PICK_UP:
            if not ctx.waiting_done:
                q1, q2 = self.inverse_kinematics(*self.coords[ctx.active_coord_key]['pick'])
                self.send_cmd(ns, q1, q2, True, ctx.target_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.MOVE_VISION_HOME_WAYPOINT; ctx.waiting_done = False

        # --- LÓGICA DE HOME CORREGIDA (NO MÁS BUCLE INFINITO) ---
        elif ctx.step == Step.MOVE_VISION_HOME_WAYPOINT:
            if not ctx.waiting_done:
                self.send_cmd(ns, -90.0, 90.0, True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx, is_home=True):
                if ctx.last_state == 0:
                    ctx.step = Step.VERIFY_HOME_POSITION
                    ctx.step_start_time = time.time()
                    # ELIMINADO: ctx.home_retries = 0 de aquí, esto era lo que causaba el fallo.
                else:
                    if ctx.home_retries < MAX_RETRIES_HOME:
                        ctx.home_retries += 1
                        ctx.waiting_done = False
                    else:
                        ctx.step = Step.VERIFY_HOME_POSITION
                        ctx.step_start_time = time.time()

        elif ctx.step == Step.VERIFY_HOME_POSITION:
            error_q1 = abs(ctx.cam_q1 - (-90.0))
            error_q2 = abs(ctx.cam_q2 - 90.0)
            
            if error_q1 < 15.0 and error_q2 < 15.0:
                ctx.step = Step.CALIBRATE_WITH_TAGS
                ctx.step_start_time = time.time()
                ctx.home_retries = 0 # Se resetea SÓLO si pasa la prueba visual
            else:
                if (time.time() - ctx.step_start_time) > 1.5:
                    if ctx.home_retries < MAX_RETRIES_HOME:
                        self.get_logger().warn(f"[{ns}] Reintentando Home. Visión reporta desfase (q1:{ctx.cam_q1:.1f}, q2:{ctx.cam_q2:.1f})")
                        ctx.home_retries += 1
                        ctx.step = Step.MOVE_VISION_HOME_WAYPOINT
                        ctx.waiting_done = False
                    else:
                        self.get_logger().error(f"[{ns}] Ignorando error visual de Home. Forzando continuación.")
                        ctx.step = Step.CALIBRATE_WITH_TAGS
                        ctx.step_start_time = time.time()
                        ctx.home_retries = 0 # O se resetea si nos saltamos el error a la fuerza

        elif ctx.step == Step.CALIBRATE_WITH_TAGS:
            if (time.time() - ctx.step_start_time) > 0.4:
                msg = Float32MultiArray()
                msg.data = [math.radians(-90.0), math.radians(90.0)]
                self.pub_set_pose[ns].publish(msg)
                ctx.step = Step.MOVE_TO_PLACE_JOINTS; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_TO_PLACE_JOINTS:
            if not ctx.waiting_done:
                idx = self.box_indices[ctx.active_coord_key]
                q1, q2, _ = self.coords[ctx.active_coord_key]['boxes_joints'][idx]
                s = self.get_servo_angle(q1, q2, 90.0)
                self.send_cmd(ns, q1 + OFFSET_WAYPOINT_PRECISION, q2, True, s)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.ROTATE_BEFORE_DROP; ctx.waiting_done = False

        elif ctx.step == Step.ROTATE_BEFORE_DROP:
            if not ctx.waiting_done:
                idx = self.box_indices[ctx.active_coord_key]
                q1, q2, off = self.coords[ctx.active_coord_key]['boxes_joints'][idx]
                s = self.get_servo_angle(q1, q2, 90.0 + ctx.picked_error_deg + off)
                self.send_cmd(ns, q1 + OFFSET_WAYPOINT_PRECISION, q2, True, s)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.PRE_PLACE_PRECISION; ctx.waiting_done = False

        elif ctx.step == Step.PRE_PLACE_PRECISION:
            if not ctx.waiting_done:
                idx = self.box_indices[ctx.active_coord_key]
                q1, q2, off = self.coords[ctx.active_coord_key]['boxes_joints'][idx]
                s = self.get_servo_angle(q1, q2, 90.0 + ctx.picked_error_deg + off)
                self.send_cmd(ns, q1, q2, True, s)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx): ctx.step = Step.PLACE_DOWN; ctx.waiting_done = False

        elif ctx.step == Step.PLACE_DOWN:
            if not ctx.waiting_done:
                idx = self.box_indices[ctx.active_coord_key]
                q1, q2, off = self.coords[ctx.active_coord_key]['boxes_joints'][idx]
                s = self.get_servo_angle(q1, q2, 90.0 + ctx.picked_error_deg + off)
                self.send_cmd(ns, q1, q2, False, s)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if (time.time() - ctx.step_start_time) > DELAY_BAJAR_CAJA:
                    ctx.step = Step.GRIP_OFF; ctx.waiting_done = False; ctx.step_start_time = time.time()

        elif ctx.step == Step.GRIP_OFF:
            self.pub_valve[ns].publish(UInt8(data=1))
            if (time.time() - ctx.step_start_time) > DELAY_SOLTAR_AIRE:
                ctx.step = Step.PLACE_UP; ctx.waiting_done = False

        elif ctx.step == Step.PLACE_UP:
            if not ctx.waiting_done:
                idx = self.box_indices[ctx.active_coord_key]
                q1, q2, _ = self.coords[ctx.active_coord_key]['boxes_joints'][idx]
                self.send_cmd(ns, q1, q2, True, 90.0)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                idx = self.box_indices[ctx.active_coord_key]
                self.box_indices[ctx.active_coord_key] = (idx + 1) % len(self.coords[ctx.active_coord_key]['boxes_joints'])
                ctx.step = Step.MOVE_HOME; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_HOME:
            if not ctx.waiting_done:
                self.send_cmd(ns, -90.0, 90.0, True)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx, is_home=True): 
                if ctx.last_state == 0:
                    ctx.step = Step.DONE; ctx.home_retries = 0
                else:
                    if ctx.home_retries < MAX_RETRIES_HOME:
                        ctx.home_retries += 1
                        ctx.waiting_done = False
                    else:
                        ctx.step = Step.DONE

        elif ctx.step == Step.DONE: ctx.step = Step.IDLE    

def main():
    rclpy.init(); node = ScaraTaskFSM()
    try: rclpy.spin(node)
    except KeyboardInterrupt: pass
    node.destroy_node(); rclpy.shutdown()

if __name__ == '__main__': main()