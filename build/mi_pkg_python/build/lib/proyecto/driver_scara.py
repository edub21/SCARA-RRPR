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

        # Posición actual en GRADOS para calcular relativos
        self.last_pos_deg = {
            'ra1': {'j1': 0.0, 'j2': 0.0},
            'ra2': {'j1': 0.0, 'j2': 0.0}
        }
        
        # Buffer de comandos: [N23, N17, SvZ(q3), SvAux(q4), Valvula(q5)]
        self.current_cmd = {
            'ra1': [0.0, 0.0, 90, 90, 0], 
            'ra2': [0.0, 0.0, 90, 90, 0]
        }

        self.robot_moving = False
        self.pending_update = False

        # Suscripciones
        for ns in ['ra1', 'ra2']:
            self.create_subscription(Float32MultiArray, f'/{ns}/joint_goals', lambda m, n=ns: self.cb_goal(m, n), 10)
            self.create_subscription(UInt8, f'/{ns}/valve_cmd', lambda m, n=ns: self.cb_valve(m, n), 10)
            
        self.pub_state_ra1 = self.create_publisher(UInt8, '/ra1/motion_state', 10)
        self.pub_state_ra2 = self.create_publisher(UInt8, '/ra2/motion_state', 10)

        self.timer = self.create_timer(0.05, self.control_loop)
        self.get_logger().info("Driver SCARA Listo. Controlando Q15/Q25 para válvulas.")

    def conectar_arduino(self):
        try:
            self.arduino = serial.Serial(PUERTO, BAUDIOS, timeout=0.1)
            time.sleep(2)
            self.arduino.reset_input_buffer()
        except:
            self.get_logger().error(f"No se pudo conectar a {PUERTO}")

    def rad2deg(self, rad):
        return rad * (180.0 / math.pi)

    def cb_goal(self, msg, ns):
        # msg: [q1_rad, q2_rad, z_logic]
        try:
            # 1. Steppers (Relativo)
            t_j1 = self.rad2deg(msg.data[0])
            t_j2 = self.rad2deg(msg.data[1])
            
            rel_j1 = t_j1 - self.last_pos_deg[ns]['j1']
            rel_j2 = t_j2 - self.last_pos_deg[ns]['j2']
            
            self.last_pos_deg[ns]['j1'] = t_j1
            self.last_pos_deg[ns]['j2'] = t_j2

            # 2. Servo Z (Prismático - qX3)
            # FSM envía 1.0 para SUBIR, 0.0 para BAJAR
            z_req = msg.data[2]
            servo_z = 180 if z_req > 0.5 else 0 

            self.current_cmd[ns][0] = rel_j1
            self.current_cmd[ns][1] = rel_j2
            self.current_cmd[ns][2] = servo_z # q3
            # q4 (indice 3) no se toca, se mantiene en init (90)
            
            self.pending_update = True
        except Exception as e:
            self.get_logger().error(f"Error goal {ns}: {e}")

    def cb_valve(self, msg, ns):
        # Mapea al indice 4 (qX5)
        self.current_cmd[ns][4] = 1 if msg.data > 0 else 0
        self.pending_update = True

    def enviar_a_arduino(self):
        if not self.arduino: return
        
        c1 = self.current_cmd['ra1']
        c2 = self.current_cmd['ra2']

        # Estructura Arduino: 
        # R1: [N23, N17, SV1(Z), SV2(Aux), ON(Valv)]
        datos = [
            c1[0], c1[1], c1[2], 90, c1[4], 
            c2[0], c2[1], c2[2], 90, c2[4]
        ]
        
        linea = ",".join(map(str, datos)) + "\n"
        self.arduino.write(linea.encode('utf-8'))
        
        # Reset incrementos steppers
        self.current_cmd['ra1'][0] = 0.0
        self.current_cmd['ra1'][1] = 0.0
        self.current_cmd['ra2'][0] = 0.0
        self.current_cmd['ra2'][1] = 0.0

    def control_loop(self):
        if not self.arduino: return

        # Leer respuesta
        if self.arduino.in_waiting:
            linea = self.arduino.readline().decode('utf-8', errors='ignore').strip()
            if "Movimiento terminado" in linea:
                self.robot_moving = False
                self.pub_state_ra1.publish(UInt8(data=0))
                self.pub_state_ra2.publish(UInt8(data=0))

        # Enviar comandos si está libre y hay cambios
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