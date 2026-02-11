# Importa la librería principal de ROS 2 en Python
import rclpy

# Importa la clase base Node, que representa un nodo en ROS 2
from rclpy.node import Node

# Importa el tipo de mensaje estándar String del paquete std_msgs
from std_msgs.msg import String

# Importa el tipo de mensaje AprilTagPixel
from avig_msg.msg import AprilTagPixel

# Define una clase que extiende Node, representando un nodo que publica mensajes
class MinimalPublisher(Node):

      def __init__(self):
         # Llama al constructor de la clase padre (Node) con el nombre del nodo
         super().__init__('minimal_publisher')

         # Crea un publicador que publica mensajes del tipo String en el topic 'topic' con una cola de 10 mensajes
         self.publisher_ = self.create_publisher(String, 'topic', 10)

         # Crea un temporizador que ejecuta la función `timer_callback` cada 0.5 segundos
         self.timer = self.create_timer(0.5, self.timer_callback)

         # Contador para numerar los mensajes
         self.i = 0

      # Función que se ejecuta cada 0.5 segundos
      def timer_callback(self):
         # Crea un mensaje tipo String
         msg = String()

         # Asigna el contenido del mensaje
         msg.data = f'Hello World: {self.i}'

         # Publica el mensaje en el topic
         self.publisher_.publish(msg)

         # Muestra por consola el mensaje publicado
         self.get_logger().info(f'Publishing: "{msg.data}"')

         # Incrementa el contador
         self.i += 1

# Punto de entrada principal del programa
def main(args=None):
      # Inicializa el sistema de nodos de ROS 2
      rclpy.init(args=args)

      try:
         # Instancia el nodo y empieza a ejecutarlo
         node = MinimalPublisher()

         # Mantiene al nodo activo, escuchando eventos y timers
         rclpy.spin(node)

      except KeyboardInterrupt:
         # Permite salir con Ctrl+C sin error
         pass

      finally:
         # Destruye el nodo de forma limpia y apaga el sistema ROS 2
         node.destroy_node()
         rclpy.shutdown()

# Verifica si el archivo se está ejecutando directamente (no importado)
if __name__ == '__main__':
      main()
