import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
import math
import time

class JointPublisher(Node):
   def __init__(self):
      super().__init__('joint_publisher_manual')
      self.pub = self.create_publisher(JointState, '/joint_states', 1)
      self.timer = self.create_timer(0.1, self.publish_joints)  # 10 Hz
      self.angulo    = 0.0
      self.distancia = 0.0
      self.signo = 1

   def publish_joints(self):
      msg = JointState()
      msg.header.stamp = self.get_clock().now().to_msg()
      msg.name = ['brazo_joint', 'antebrazo_joint', 'efector_joint']

      # Movimiento sinusoidal para prueba
      brazo     = math.sin(self.angulo)
      antebrazo = math.cos(self.angulo)
      efector   = self.distancia

      msg.position = [brazo, antebrazo, efector]

      self.pub.publish(msg)
      self.get_logger().info(f'Publicando: brazo={brazo:.2f}, antebrazo={antebrazo:.2f}, efector {efector:.2f}')

      if self.distancia >= 0.040:
            self.signo = -1

      if self.distancia <= 0.000:
            self.signo = 1

      self.distancia += 0.001*self.signo
      self.angulo += 0.005

def main(args=None):
   rclpy.init(args=args)
   node = JointPublisher()
   rclpy.spin(node)
   node.destroy_node()
   rclpy.shutdown()