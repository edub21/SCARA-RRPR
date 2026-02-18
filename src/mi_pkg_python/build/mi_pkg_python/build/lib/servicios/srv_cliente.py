import rclpy
from rclpy.node import Node

from avig_msg.srv import Heuristica
from avig_msg.msg import AprilTagPixel, AprilTagPixelArray

class EuristicaClient(Node):
   def __init__(self):
      super().__init__('euristica_client')
      self.client = self.create_client(Heuristica, 'Heuristica')

      while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Esperando al servicio...')

      # Crear solicitud con varios tags
      msg_array = AprilTagPixelArray()
      for i in range(10, 19, 1):
            tag = AprilTagPixel()
            tag.id = i
            tag.posx = float(100 - i*2)
            tag.posy = float(50  + i*2)
            msg_array.tags.append(tag)

      tag = AprilTagPixel()
      tag.id = 1
      tag.posx = -20.0
      tag.posy = 170.0
      msg_array.tags.append(tag)

      tag = AprilTagPixel()
      tag.id = 2
      tag.posx = 105.2
      tag.posy = 23.5
      msg_array.tags.append(tag)

      request = Heuristica.Request()
      request.tags_in = msg_array

      self.future = self.client.call_async(request)

def main(args=None):
   rclpy.init(args=args)
   node = EuristicaClient()

   while rclpy.ok():
      rclpy.spin_once(node)
      if node.future.done():
            try:
               response = node.future.result()
               node.get_logger().info(f"Tag seleccionado: {response.tag_out}")

               node.get_logger().info(f"Tag ID: {response.tag_out.id} "
                                       f"({response.tag_out.posx:.1f}, {response.tag_out.posy:.1f})")
            except Exception as e:
               node.get_logger().error(f"Error al llamar al servicio: {e}")
            break

   rclpy.shutdown()

if __name__ == '__main__':
   main()