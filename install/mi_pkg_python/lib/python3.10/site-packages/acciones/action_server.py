import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from avig_msg.action import MoverA
import math

# Definición de la clase del servidor de acción
class MoverAServer(Node):
   def __init__(self):
      # Inicializa el nodo con nombre 'movera_server'
      super().__init__('movera_server')

      # Crea un servidor de acción para la acción personalizada 'MoverA'
      self._action_server = ActionServer(
            self,
            MoverA,
            'mover_a',  # Nombre del tópico de acción
            execute_callback=self.execute_callback,  # Lógica principal de ejecución
            goal_callback=self.goal_callback,        # Qué hacer cuando llega una meta
            cancel_callback=self.cancel_callback     # Qué hacer si el cliente pide cancelar
      )

      self.goal_handle = None  # Guardará el manejador de la meta actual
      self.timer = None        # Temporizador usado para simular movimiento

   # Callback que se ejecuta cuando se recibe una nueva meta
   def goal_callback(self, goal_request):
      self.get_logger().info('Objetivo recibido.')
      return GoalResponse.ACCEPT  # Acepta todas las metas que recibe

   # Callback que se ejecuta cuando se solicita cancelar una meta
   def cancel_callback(self, goal_handle):
      self.get_logger().info('Cancelación solicitada.')
      return CancelResponse.ACCEPT  # Acepta siempre la cancelación

   # Lógica principal que se ejecuta cuando la meta ha sido aceptada
   async def execute_callback(self, goal_handle):
      self.goal_handle = goal_handle

      # Extrae posición inicial y meta desde la solicitud
      self.x_actual = goal_handle.request.x_actual
      self.y_actual = goal_handle.request.y_actual
      self.x_goal = goal_handle.request.x_meta
      self.y_goal = goal_handle.request.y_meta
      self.step_size = 0.1  # Tamaño de paso por iteración

      # Crea el objeto de feedback que será enviado al cliente
      self.feedback_msg = MoverA.Feedback()

      self.get_logger().info(f'Iniciando movimiento: ({self.x_actual:.2f}, {self.y_actual:.2f}) → ({self.x_goal:.2f}, {self.y_goal:.2f})')

      # Crea un temporizador que se ejecuta cada 0.5 segundos
      self.timer = self.create_timer(0.5, self.update_position)

      # Bucle que espera mientras se ejecuta el temporizador
      while not goal_handle.is_cancel_requested and self.distance(self.x_actual, self.y_actual) > 0.1:
            # Procesa eventos del temporizador
            rclpy.spin_once(self, timeout_sec=0.1)

      # Si el cliente cancela la acción
      if goal_handle.is_cancel_requested:
            self.timer.cancel()            # Detiene el temporizador
            goal_handle.canceled()        # Informa al cliente que fue cancelado
            self.get_logger().warn("Objetivo cancelado por el cliente")
            return MoverA.Result(success=False)

      # Si se llegó al destino
      self.timer.cancel()                # Detiene el temporizador
      goal_handle.succeed()             # Marca como completado con éxito
      self.get_logger().info("Objetivo alcanzado")
      return MoverA.Result(success=True)

   # Función ejecutada periódicamente por el temporizador
   def update_position(self):
      if not self.goal_handle:
            return

      # Calcula la distancia restante
      dist = self.distance(self.x_actual, self.y_actual)
      if dist <= 0.1:
            return  # Ya está suficientemente cerca

      # Simula movimiento en línea recta hacia la meta
      self.x_actual += self.step_size * (self.x_goal - self.x_actual) / dist
      self.y_actual += self.step_size * (self.y_goal - self.y_actual) / dist

      # Calcula nueva distancia y envía feedback
      dist = self.distance(self.x_actual, self.y_actual)
      self.feedback_msg.distancia_restante = float(dist)
      self.goal_handle.publish_feedback(self.feedback_msg)
      self.get_logger().info(f"Distancia restante: {dist:.2f}")

   # Función auxiliar para calcular la distancia euclidiana al objetivo
   def distance(self, x, y):
      return math.sqrt((x - self.x_goal)**2 + (y - self.y_goal)**2)

# Función principal para ejecutar el servidor de acción
def main(args=None):
   rclpy.init(args=args)
   node = MoverAServer()  # Crea el servidor
   rclpy.spin(node)       # Mantiene el nodo activo
   rclpy.shutdown()       # Apaga ROS 2 cuando termina

if __name__ == '__main__':
   main()