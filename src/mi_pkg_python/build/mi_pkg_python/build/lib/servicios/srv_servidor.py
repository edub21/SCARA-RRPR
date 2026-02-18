import rclpy
from rclpy.node import Node
from avig_msg.srv import Heuristica
from avig_msg.msg import AprilTagPixel
import math

class EuristicaServer(Node):
   def __init__(self):
      super().__init__('euristica_server')
      self.srv = self.create_service(Heuristica, 'Heuristica', self.heuristica_callback)
      self.get_logger().info('Servicio Euristica listo.')

   def heuristica_callback(self, request, response):
      tags = request.tags_in.tags
      self.get_logger().info(f"Recibidos {tags} tags.")

      if not tags:
            self.get_logger().warn("No se recibió ningún tag.")
            return response

      tag1 = next((tag for tag in tags if tag.id == 1), None)
      tag2 = next((tag for tag in tags if tag.id == 2), None)

      if tag1 is None or tag2 is None:
            self.get_logger().warn("Faltan tag1 o tag2, no se puede continuar.")
            return response


      tags_ordenados = [tag for tag in tags if tag.id != 0 and tag.id != 1 and tag.id != 2]

      for i, tag in enumerate(tags_ordenados):
            self.get_logger().info(f"Revisando el tag: {tag.id}")
            if 10 <= tag.id < 20:
               tag.dist = math.sqrt((tag.posx - tag1.posx)**2 + (tag.posy - tag1.posy)**2)
            else:
               tag.dist = math.sqrt((tag.posx - tag2.posx)**2 + (tag.posy - tag2.posy)**2)

            self.get_logger().info(f"Distancia del Tag: {tag.id} es {tag.dist}")

      # Heurística: devolver el tag con menor coordenada posx
      tag_ordenado = sorted(tags_ordenados, key=lambda t: t.dist)[0]
      response.tag_out = tag_ordenado
      self.get_logger().info(f"Tag elegido: {tag_ordenado.id}")
      return response

def main(args=None):
   rclpy.init(args=args)
   node = EuristicaServer()
   rclpy.spin(node)
   rclpy.shutdown()

if __name__ == '__main__':
   main()