import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

class JointMonitor(Node):
   def __init__(self):
      super().__init__('joint_monitor')
      self.subscription = self.create_subscription(
            JointState,
            '/joint_states',
            self.callback,
            1
      )

   def callback(self, msg):
      for i, name in enumerate(msg.name):
            if name == "brazo_joint" or name == "antebrazo_joint" or name == "efector_joint":
               self.get_logger().info(f"{name} → {msg.position[i]:.3f} rad")

def main(args=None):
   rclpy.init(args=args)
   node = JointMonitor()
   rclpy.spin(node)
   node.destroy_node()
   rclpy.shutdown()