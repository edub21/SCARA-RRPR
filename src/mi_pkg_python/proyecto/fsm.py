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
        
        # NUEVO: Banderas de calibración inicial
        self.camera_ready = False
        self.init_calibrated = False
        
        self.cam_q1 = -90.0
        self.cam_q2 = 90.0
        self.cmd_q1 = -90.0
        self.cmd_q2 = 90.0

class ScaraTaskFSM(Node):
    def __init__(self):
        super().__init__('scara_task_fsm')

        self.robots = {'ra1': RobotContext('ra1'), 'ra2': RobotContext('ra2')}
        
        # ================= COORDENADAS =================
        self.coords = {
            'ra1': {
                'home_coords': (20, 20), 
                'pick': (32, 0.0),
                'waypoint': (20.0, -15.0), 
                'boxes': [(15.5, -24.0), (15.5, -30.5), (9, -24.0), (9, -30.5)]
            },
            'ra2': {
                'home_coords': (20, 20),
                'pick': (31, 0.0),
                'waypoint': (20.0, -15.0),
                'boxes': [(-10.0, -25.0), (-10.0, -35.0), (0.0, -25.0), (0.0, -35.0)]
            }
        }

        self.effector_settle_sec = 0.5 

        self.pub_goals = {}
        self.pub_valve = {}
        self.pub_set_pose = {} # NUEVO: Publicador para set_pose
        self.sub_state = {}

        self.latest_raw_deg = {'ra1': 0.0, 'ra2': 0.0}

        self.create_subscription(Int32, '/sistema/trigger', self._on_trigger, 10)
        self.create_subscription(ObjDetect, '/detected_objects', self._on_obj_detect, 10)

        self.create_subscription(JointState, '/r1/joint_states', lambda msg: self._on_joint_states('ra1', msg), 10)
        self.create_subscription(JointState, '/r2/joint_states', lambda msg: self._on_joint_states('ra2', msg), 10)

        for ns in self.robots:
            self.pub_goals[ns] = self.create_publisher(Float32MultiArray, f'/{ns}/joint_goals', 10)
            self.pub_valve[ns] = self.create_publisher(UInt8, f'/{ns}/valve_cmd', 10)
            self.pub_set_pose[ns] = self.create_publisher(Float32MultiArray, f'/{ns}/set_pose', 10) # NUEVO
            self.sub_state[ns] = self.create_subscription(
                UInt8, f'/{ns}/motion_state',
                lambda msg, n=ns: self._on_motion_state(n, msg), 10
            )

        self.timer = self.create_timer(0.1, self._tick)
        self.get_logger().info('FSM Listo: Inicio Inteligente con Cámara y Gimbal Absoluto.')

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

    # ================= GIMBAL ABSOLUTO =================
    def get_compensated_orient(self, tx, ty, target_abs_deg=90.0):
        q1_rad, q2_rad = self.inverse_kinematics(tx, ty)
        place_arm = math.degrees(q1_rad) + math.degrees(q2_rad)
        ideal_servo = target_abs_deg + 90.0 - place_arm
        return ideal_servo % 180.0

    # ================= CALLBACKS =================
    def _on_joint_states(self, ns, msg):
        ctx = self.robots[ns]
        ctx.camera_ready = True # Avisa que la cámara está viva
        prefix = 'r1' if ns == 'ra1' else 'r2'
        
        for i, name in enumerate(msg.name):
            if name == f'{prefix}_brazo_joint':
                ctx.cam_q1 = math.degrees(msg.position[i])
            elif name == f'{prefix}_antebrazo_joint':
                ctx.cam_q2 = math.degrees(msg.position[i])

    def _on_obj_detect(self, msg):
        deg = math.degrees(msg.orient)
        if 30 <= msg.id < 40:
            self.latest_raw_deg['ra1'] = deg
        elif 40 <= msg.id < 50:
            self.latest_raw_deg['ra2'] = deg

    def _on_trigger(self, msg):
        target = msg.data
        ns = None
        if target == 1: ns = 'ra1'
        elif target == 2: ns = 'ra2'
        
        if ns:
            ctx = self.robots[ns]
            if ctx.step == Step.IDLE or ctx.step == Step.DONE:
                self.get_logger().info(f"[{ns}] CAJA {ctx.target_box_idx + 1}")
                
                tx, ty = self.coords[ns]['pick']
                q1_rad, q2_rad = self.inverse_kinematics(tx, ty)
                pick_arm = math.degrees(q1_rad) + math.degrees(q2_rad)
                
                obj_deg = self.latest_raw_deg[ns]
                
                pick_servo = 90.0 + obj_deg - pick_arm
                ctx.target_orient = pick_servo % 180.0
                
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
    def send_robot_cmd_xy(self, ns, x, y, z_up, orient=90.0):
        q1_rad, q2_rad = self.inverse_kinematics(x, y)
        self.robots[ns].cmd_q1 = math.degrees(q1_rad)
        self.robots[ns].cmd_q2 = math.degrees(q2_rad)

        msg = Float32MultiArray()
        msg.data = [float(q1_rad), float(q2_rad), float(1.0 if z_up else 0.0), float(orient)]
        self.pub_goals[ns].publish(msg)

    def send_robot_cmd_raw(self, ns, q1_deg, q2_deg, z_up, orient=90.0):
        self.robots[ns].cmd_q1 = q1_deg
        self.robots[ns].cmd_q2 = q2_deg

        r1 = math.radians(q1_deg)
        r2 = math.radians(q2_deg)
        msg = Float32MultiArray()
        msg.data = [float(r1), float(r2), float(1.0 if z_up else 0.0), float(orient)]
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
        
        # --- 0. INICIO INTELIGENTE ---
        if ctx.step == Step.INIT_SEQUENCE:
            if not ctx.waiting_done:
                
                # 1. Esperamos a que la cámara detecte los brazos
                if not ctx.camera_ready:
                    return 
                
                # 2. Le avisamos al Arduino dónde está exactamente
                if not ctx.init_calibrated:
                    msg_pose = Float32MultiArray()
                    msg_pose.data = [float(math.radians(ctx.cam_q1)), float(math.radians(ctx.cam_q2))]
                    self.pub_set_pose[ns].publish(msg_pose)
                    
                    ctx.cmd_q1 = ctx.cam_q1
                    ctx.cmd_q2 = ctx.cam_q2
                    ctx.init_calibrated = True
                    self.get_logger().info(f"[{ns}] Calibración inicial (Cámara): Q1={ctx.cam_q1:.1f}, Q2={ctx.cam_q2:.1f}")
                    return # Damos un ciclo para que el driver asimile la posición real

                # 3. Calculamos la ruta hacia HOME desde donde sea que esté
                target_q1 = -90.0
                target_q2 = 90.0
                
                error_q1 = target_q1 - ctx.cam_q1
                error_q2 = target_q2 - ctx.cam_q2
                
                cmd_compensado_q1 = ctx.cmd_q1 + error_q1
                cmd_compensado_q2 = ctx.cmd_q2 + error_q2
                
                self.pub_valve[ns].publish(UInt8(data=1)) # OFF al inicio
                self.send_robot_cmd_raw(ns, cmd_compensado_q1, cmd_compensado_q2, z_up=True, orient=90.0)
                
                self.get_logger().info(f"[{ns}] Moviéndose a HOME de forma segura...")
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
                
            elif self.check_done(ns, ctx):
                # === RESETEO DESPUÉS DEL INICIO ===
                msg_pose = Float32MultiArray()
                msg_pose.data = [float(math.radians(-90.0)), float(math.radians(90.0))]
                self.pub_set_pose[ns].publish(msg_pose)
                
                ctx.cmd_q1 = -90.0
                ctx.cmd_q2 = 90.0
                
                self.get_logger().info(f"[{ns}] ¡Inicializado y memoria en HOME exacto (-90, 90)!")
                ctx.step = Step.IDLE

        elif ctx.step == Step.IDLE:
            return

        elif ctx.step == Step.MOVE_TO_PICK_XY:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=True, orient=ctx.target_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
                self.get_logger().info(f"[{ns}] 1. Pick ({tx}, {ty}) Ori:{ctx.target_orient:.1f}°")
            elif self.check_done(ns, ctx):
                ctx.step = Step.PICK_DOWN; ctx.waiting_done = False

        elif ctx.step == Step.PICK_DOWN:
            if not ctx.waiting_done:
                tx, ty = self.coords[ns]['pick']
                self.send_robot_cmd_xy(ns, tx, ty, z_up=False, orient=ctx.target_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, 0.5): 
                    ctx.step = Step.GRIP_ON
                    ctx.waiting_done = False

        elif ctx.step == Step.GRIP_ON:
            self.pub_valve[ns].publish(UInt8(data=0))
            if self.wait_timer(ctx, self.effector_settle_sec):
                ctx.step = Step.MOVE_AVOID_OBSTACLE; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_AVOID_OBSTACLE:
            if not ctx.waiting_done:
                wx, wy = self.coords[ns]['waypoint']
                comp_orient = self.get_compensated_orient(wx, wy, target_abs_deg=90.0)
                self.send_robot_cmd_xy(ns, wx, wy, z_up=True, orient=comp_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                ctx.step = Step.MOVE_TO_PLACE_XY; ctx.waiting_done = False

        elif ctx.step == Step.MOVE_TO_PLACE_XY:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                comp_orient = self.get_compensated_orient(bx, by, target_abs_deg=90.0)
                self.send_robot_cmd_xy(ns, bx, by, z_up=True, orient=comp_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                ctx.step = Step.PLACE_DOWN; ctx.waiting_done = False

        elif ctx.step == Step.PLACE_DOWN:
            if not ctx.waiting_done:
                bx, by = self.coords[ns]['boxes'][ctx.target_box_idx]
                comp_orient = self.get_compensated_orient(bx, by, target_abs_deg=90.0)
                self.send_robot_cmd_xy(ns, bx, by, z_up=False, orient=comp_orient)
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                if self.wait_timer(ctx, 0.5): 
                    ctx.step = Step.GRIP_OFF
                    ctx.waiting_done = False

        elif ctx.step == Step.GRIP_OFF:
            self.pub_valve[ns].publish(UInt8(data=1)) 
            if self.wait_timer(ctx, self.effector_settle_sec):
                ctx.step = Step.MOVE_HOME; ctx.waiting_done = False

        # --- HOME CORREGIDO CON VISIÓN ---
        elif ctx.step == Step.MOVE_HOME:
            if not ctx.waiting_done:
                target_q1 = -90.0
                target_q2 = 90.0
                
                error_q1 = target_q1 - ctx.cam_q1
                error_q2 = target_q2 - ctx.cam_q2
                
                cmd_compensado_q1 = ctx.cmd_q1 + error_q1
                cmd_compensado_q2 = ctx.cmd_q2 + error_q2
                
                self.send_robot_cmd_raw(ns, cmd_compensado_q1, cmd_compensado_q2, z_up=True, orient=90.0)
                
                ctx.waiting_done = True; ctx.seen_moving = False; ctx.step_start_time = time.time()
            elif self.check_done(ns, ctx):
                
                # === RESETEO DESPUÉS DE CADA CICLO ===
                msg_pose = Float32MultiArray()
                msg_pose.data = [float(math.radians(-90.0)), float(math.radians(90.0))]
                self.pub_set_pose[ns].publish(msg_pose)
                
                # Sincronizamos el FSM con la realidad física
                ctx.cmd_q1 = -90.0
                ctx.cmd_q2 = 90.0
                
                self.get_logger().info(f"[{ns}] Memoria reseteada a Home exacto (-90, 90).")
                
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