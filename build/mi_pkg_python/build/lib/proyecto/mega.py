import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray, UInt8
import serial
import time
import math

class MegaDriverNode(Node):
    def __init__(self):
        super().__init__('driver_arduino')
        
        # ================= CONFIGURACIÓN SERIAL =================
        self.declare_parameter('port', '/dev/ttyACM0')
        self.declare_parameter('baud', 9600)
        
        puerto = self.get_parameter('port').get_parameter_value().string_value
        baud = self.get_parameter('baud').get_parameter_value().integer_value

        try:
            self.ser = serial.Serial(puerto, baud, timeout=1)
            self.get_logger().info(f"Conectado a Arduino en {puerto}")
            time.sleep(2) # Espera reinicio
        except Exception as e:
            self.get_logger().error(f"Error Serial: {e}")
            raise e

        # ================= ESTADO DE LOS ROBOTS =================
        # [R1_N23, R1_N17, R1_Z, R2_N23, R2_N17, R2_Z, R1_V, R2_V]
        self.current_goals = [0.0] * 10 
        
        # ================= SUBSCRIPTORES =================
        # Escucha de Robot 1
        self.create_subscription(Float32MultiArray, '/ra1/joint_goals', self.r1_callback, 10)
        self.create_subscription(UInt8, '/ra1/valve_cmd', self.v1_callback, 10)
        
        # Escucha de Robot 2
        self.create_subscription(Float32MultiArray, '/ra2/joint_goals', self.r2_callback, 10)
        self.create_subscription(UInt8, '/ra2/valve_cmd', self.v2_callback, 10)

        # Publicador de estado (para que la FSM sepa que terminó)
        self.pub_state_r1 = self.create_publisher(UInt8, '/ra1/motion_state', 10)
        self.pub_state_r2 = self.create_publisher(UInt8, '/ra2/motion_state', 10)

        self.get_logger().info("Nodo Mega Driver listo y escuchando comandos...")

    def r1_callback(self, msg):
        # msg.data = [q1_rad, q2_rad, z_bool]
        q1_deg = math.degrees(msg.data[0])
        q2_deg = math.degrees(msg.data[1])
        # Actualizamos parte del comando final
        self.current_goals[0] = q1_deg
        self.current_goals[1] = q2_deg
        # Lógica de servos según tu URDF
        self.current_goals[2] = 45 if msg.data[2] > 0.5 else 90 # Ejemplo
        self.enviar_a_arduino()

    def r2_callback(self, msg):
        q1_deg = math.degrees(msg.data[0])
        q2_deg = math.degrees(msg.data[1])
        self.current_goals[5] = q1_deg
        self.current_goals[6] = q2_deg
        self.enviar_a_arduino()

    def v1_callback(self, msg):
        self.current_goals[4] = msg.data
        self.enviar_a_arduino()

    def v2_callback(self, msg):
        self.current_goals[9] = msg.data
        self.enviar_a_arduino()

    def enviar_a_arduino(self):
        # Convertir lista a string CSV
        mensaje = ",".join(map(lambda x: f"{x:.2f}", self.current_goals)) + "\n"
        self.ser.write(mensaje.encode('utf-8'))
        
        # Esperar respuesta "Movimiento terminado"
        while True:
            if self.ser.in_waiting > 0:
                linea = self.ser.readline().decode('utf-8', errors='ignore').strip()
                if "Movimiento terminado" in linea:
                    # Notificar a ROS que estamos libres
                    self.pub_state_r1.publish(UInt8(data=0))
                    self.pub_state_r2.publish(UInt8(data=0))
                    break

# ================= FUNCIÓN MAIN (ESTO ES LO QUE TE FALTABA) =================
def main(args=None):
    rclpy.init(args=args)
    try:
        node = MegaDriverNode()
        rclpy.spin(node)
    except Exception as e:
        print(f"Error en el nodo Mega: {e}")
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()