import rclpy
from rclpy.node import Node

from rclpy.action import ActionClient
from avig_msg.action import MoverA  # Importa la acción personalizada

# Definición de la clase cliente de acción
class MoverAClient(Node):
   def __init__(self):
      # Inicializa el nodo con nombre 'movera_client'
      super().__init__('movera_client')
      # Crea un cliente de acción para comunicarse con el servidor
      self._client = ActionClient(self, MoverA, 'mover_a')
      self._goal_handle = None  # Guardará la referencia a la meta enviada

   # Método para enviar una meta al servidor de acción
   def send_goal(self, xi, yi, xm, ym):
      # Define los valores de posición inicial y objetivo
      goal_msg = MoverA.Goal()
      goal_msg.x_actual = xi
      goal_msg.y_actual = yi
      goal_msg.x_meta = xm
      goal_msg.y_meta = ym

      # Espera a que el servidor esté disponible
      self._client.wait_for_server()

      self.get_logger().info(f'Enviando objetivo: x={xi}, y={yi} → x={xm}, y={ym}')

      # Envía la meta de forma asíncrona y se suscribe a feedback
      self._send_goal_future = self._client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
      )
      self._send_goal_future.add_done_callback(self.goal_response_callback)

   # Callback que se ejecuta cada vez que el servidor envía feedback
   def feedback_callback(self, feedback_msg):
      dist = feedback_msg.feedback.distancia_restante
      self.get_logger().info(f'Feedback: distancia restante = {dist:.2f}')

      # Lógica personalizada: si estamos suficientemente cerca, solicitamos cancelación
      if dist < 0.8 and self._goal_handle is not None:
            self.get_logger().warn('Cancelando acción por distancia < 0.3...')
            cancel_future = self._goal_handle.cancel_goal_async()
            cancel_future.add_done_callback(self.cancel_callback)

   # Callback que se ejecuta cuando el servidor responde si acepta o no la meta
   def goal_response_callback(self, future):
      self._goal_handle = future.result()
      if not self._goal_handle.accepted:
            self.get_logger().error('Objetivo rechazado.')
            return

      self.get_logger().info('Objetivo aceptado.')
      # Espera de forma asíncrona el resultado final
      self._get_result_future = self._goal_handle.get_result_async()
      self._get_result_future.add_done_callback(self.result_callback)

   # Callback que se ejecuta cuando se responde la solicitud de cancelación
   def cancel_callback(self, future):
      cancel_response = future.result()
      if len(cancel_response.goals_canceling) > 0:
            self.get_logger().info('Acción cancelada exitosamente.')
      else:
            self.get_logger().info('No se pudo cancelar la acción.')

   # Callback que se ejecuta cuando se recibe el resultado final del servidor
   def result_callback(self, future):
      result = future.result().result
      if result.success:
            self.get_logger().info('Llegamos al destino.')
      else:
            self.get_logger().info('Acción no completada.')
      rclpy.shutdown()

# Función principal para ejecutar el cliente
def main(args=None):
   rclpy.init(args=args)
   node = MoverAClient()
   # Envía una meta de ejemplo
   node.send_goal(2.0, 3.0, 0.0, 0.1)
   # Mantiene el nodo activo mientras espera feedback/resultados
   rclpy.spin(node)

if __name__ == '__main__':
   main()