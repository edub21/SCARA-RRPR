# Importa la librería principal de ROS 2 para Python
import rclpy

# Importa la clase base para crear nodos en ROS 2
from rclpy.node import Node

# Importa el tipo de mensaje estándar String desde std_msgs
from std_msgs.msg import String

# Define una clase que hereda de Node, representa el nodo suscriptor
class MinimalSubscriber(Node):

      # Método constructor de la clase
      def __init__(self):
         # Inicializa el nodo con el nombre 'minimal_subscriber'
         super().__init__('minimal_subscriber')

         # Crea una suscripción al tópico 'topic'
         # Tipo de mensaje: String
         # Función de callback: self.listener_callback
         # Tamaño de la cola: 10 mensajes
         self.subscription = self.create_subscription(
            String,
            'topic',
            self.listener_callback,
            10)

         # Esta línea asegura que la variable no sea optimizada por el compilador (aunque no es obligatorio en Python)
         self.subscription

      # Función que se llama cada vez que se recibe un mensaje en el tópico
      def listener_callback(self, msg):
         # Imprime en consola el contenido del mensaje recibido
         self.get_logger().info('I heard: "%s"' % msg.data)

# Función principal que lanza el nodo
def main(args=None):
      # Inicializa el sistema de ROS 2
      rclpy.init(args=args)

      # Crea una instancia del nodo suscriptor
      minimal_subscriber = MinimalSubscriber()

      # Mantiene el nodo corriendo escuchando datos (callback se ejecutará cuando lleguen mensajes)
      rclpy.spin(minimal_subscriber)

      # Cuando se detiene (Ctrl+C o cierre), se destruye el nodo explícitamente (opcional)
      minimal_subscriber.destroy_node()

      # Finaliza la ejecución del sistema ROS 2
      rclpy.shutdown()

# Esta verificación permite que el nodo se ejecute solo si el script se corre directamente
if __name__ == '__main__':
      main()
