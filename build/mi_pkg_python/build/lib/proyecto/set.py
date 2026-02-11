import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
import math



class JointInitializer(Node):
   def __init__(self):
      super().__init__('init_joints')
      self.publisher_r1 = self.create_publisher(JointState, 'r1/joint_states', 1)
      self.publisher_r2 = self.create_publisher(JointState, 'r2/joint_states', 1)

      # Publicar al iniciar
      self.timer = self.create_timer(0.5, self.publicar_posicion)

   def publicar_posicion(self):
      msg_r1 = JointState()
      msg_r1.header.stamp = self.get_clock().now().to_msg()
      msg_r1.name = ['r1_brazo_joint', 'r1_antebrazo_joint', 'r1_efector_joint']
      msg_r1.position = [math.radians(90), math.radians(0), math.radians(0)]

      msg_r2 = JointState()
      msg_r2.header.stamp = self.get_clock().now().to_msg()
      msg_r2.name = ['r2_brazo_joint', 'r2_antebrazo_joint', 'r2_efector_joint']
      msg_r2.position = [math.radians(90), math.radians(0), math.radians(0)]

      self.publisher_r1.publish(msg_r1)
      self.publisher_r2.publish(msg_r2)
      self.get_logger().info('Postura inicial publicada.')
      # Detener timer y cerrar limpio
      self.timer.cancel()
      self.destroy_node()
      rclpy.shutdown()

def main(args=None):
   rclpy.init(args=args)
   node = JointInitializer()
   rclpy.spin(node)

if __name__ == '__main__':
   main()