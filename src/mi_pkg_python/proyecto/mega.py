import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray, UInt8
import serial
import time
import math

PUERTO = '/dev/ttyACM0' 
BAUDIOS = 9600

class ScaraDriver(Node):
    def __init__(self):
        super().__init__('scara_driver')
        
        self.arduino = None
        self.conectar_arduino()

        self.last_pos_deg = {
            'ra1': {'j1': 0.0, 'j2': 0.0},
            'ra2': {'j1': 0.0, 'j2': 0.0}
        }
        
        self.current_cmd = {
            # j1_rel, j2_rel, z_servo, orient_servo, valve
            'ra1': [0.0, 0.0, 90.0, 90.0, 0], 
            'ra2': [0.0, 0.0, 90.0, 90.0, 0]
        }

        self.robot_moving = False
        self.pending_update = False

        for ns in ['ra1', 'ra2']:
            self.create_subscription(Float32MultiArray, f'/{ns}/joint_goals', lambda m, n=ns: self.cb_goal(m, n), 10)
            self.create_subscription(UInt8, f'/{ns}/valve_cmd', lambda m, n=ns: self.cb_valve(m, n), 10)
            self.create_subscription(Float32MultiArray, f'/{ns}/set_pose', lambda m, n=ns: self.cb_set_pose(m, n), 10)
            
        self.pub_state_ra1 = self.create_publisher(UInt8, '/ra1/motion_state', 10)
        self.pub_state_ra2 = self.create_publisher(UInt8, '/ra2/motion_state', 10)

        self.timer = self.create_timer(0.05, self.control_loop)
        self.get_logger().info("Driver SCARA Listo con Orientación dinámica.")

    def conectar_arduino(self):
        try:
            self.arduino = serial.Serial(PUERTO, BAUDIOS, timeout=0.1)
            time.sleep(2)
            self.arduino.reset_input_buffer()
        except:
            self.get_logger().error(f"No se pudo conectar a {PUERTO}")

    def rad2deg(self, rad):
        return rad * (180.0 / math.pi)

    def cb_set_pose(self, msg, ns):
        try:
            j1_deg = self.rad2deg(msg.data[0])
            j2_deg = self.rad2deg(msg.data[1])
            
            self.last_pos_deg[ns]['j1'] = j1_deg
            self.last_pos_deg[ns]['j2'] = j2_deg
            self.get_logger().info(f"[{ns}] CALIBRADO: j1={j1_deg:.2f}, j2={j2_deg:.2f}")
        except Exception as e:
            self.get_logger().error(f"Error en set_pose: {e}")

    def cb_goal(self, msg, ns):
        try:
            t_j1 = self.rad2deg(msg.data[0])
            t_j2 = self.rad2deg(msg.data[1])
            
            rel_j1 = t_j1 - self.last_pos_deg[ns]['j1']
            rel_j2 = t_j2 - self.last_pos_deg[ns]['j2']
            
            self.last_pos_deg[ns]['j1'] = t_j1
            self.last_pos_deg[ns]['j2'] = t_j2

            z_req = msg.data[2]
            servo_z = 180 if z_req > 0.5 else -90 

            self.current_cmd[ns][0] = rel_j1
            self.current_cmd[ns][1] = rel_j2
            self.current_cmd[ns][2] = servo_z 
            
            # NUEVO: Guardar la orientación enviada por el FSM
            if len(msg.data) >= 4:
                self.current_cmd[ns][3] = msg.data[3]
            else:
                self.current_cmd[ns][3] = 90.0
            
            self.pending_update = True
        except Exception as e:
            self.get_logger().error(f"Error goal {ns}: {e}")

    def cb_valve(self, msg, ns):
        self.current_cmd[ns][4] = 1 if msg.data > 0 else 0
        self.pending_update = True

    def enviar_a_arduino(self):
        if not self.arduino: return
        c1 = self.current_cmd['ra1']
        c2 = self.current_cmd['ra2']
        
        # NUEVO: Se envía c1[3] y c2[3] correspondientes a la orientación, en lugar del '90' estático
        datos = [
            c1[0], c1[1], c1[2], c1[3], c1[4], 
            c2[0], c2[1], c2[2], c2[3], c2[4]
        ]
        linea = ",".join(map(str, datos)) + "\n"
        self.arduino.write(linea.encode('utf-8'))
        
        # Reset de los pasos relativos
        self.current_cmd['ra1'][0] = 0.0; self.current_cmd['ra1'][1] = 0.0
        self.current_cmd['ra2'][0] = 0.0; self.current_cmd['ra2'][1] = 0.0

    def control_loop(self):
        if not self.arduino: return
        if self.arduino.in_waiting:
            linea = self.arduino.readline().decode('utf-8', errors='ignore').strip()
            if "Movimiento terminado" in linea:
                self.robot_moving = False
                self.pub_state_ra1.publish(UInt8(data=0))
                self.pub_state_ra2.publish(UInt8(data=0))

        if self.pending_update and not self.robot_moving:
            self.enviar_a_arduino()
            self.robot_moving = True
            self.pending_update = False
            self.pub_state_ra1.publish(UInt8(data=1))
            self.pub_state_ra2.publish(UInt8(data=1))

def main():
    rclpy.init()
    node = ScaraDriver()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt: pass
    finally:
        if node.arduino: node.arduino.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()