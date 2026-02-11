import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray, UInt8
import math

class Float32MultiArrayPruebas(Node):
    def __init__(self):
        super().__init__('init_joints')
        
        self.publisher_r1 = self.create_publisher(Float32MultiArray, 'ra1/joint_goals_q', 10)
        self.publisher_r2 = self.create_publisher(Float32MultiArray, 'ra2/joint_goals_q', 10)

        self.publisher_state_r1 = self.create_publisher(Float32MultiArray, 'ra1/motion_state', 1)
        self.publisher_state_r2 = self.create_publisher(Float32MultiArray, 'ra2/motion_state', 1)
        

        # Publicar una vez después de 0.5s (para dar tiempo a que existan subscribers)
        self.timer = self.create_timer(0.5, self.publicar_posicion)
        self.publicado = False

    def publicar_posicion(self):
        if self.publicado:
            return
        self.publicado = True

        q1 = float(input("ingresar q1"))
        q2 = float(input("ingresar q2"))

        msg_r1 = Float32MultiArray()
        msg_r1.data = [math.radians(q1), math.radians(q2), 0.2]

        msg_r2 = Float32MultiArray()
        msg_r2.data = [math.radians(10), math.radians(20), ]

        self.publisher_r1.publish(msg_r1)
        self.publisher_r2.publish(msg_r2)
        self.get_logger().info('Postura publicada.')

def main(args=None):
    rclpy.init(args=args)
    node = Float32MultiArrayPruebas()
    rclpy.spin(node)

if __name__ == '__main__':
    main()
