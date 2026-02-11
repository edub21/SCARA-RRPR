# Importa las clases necesarias de tf2 para escuchar transformaciones
from tf2_ros import TransformListener, Buffer

# Importa la API principal de ROS 2 en Python
import rclpy
from rclpy.node import Node

# Define una clase que extiende de Node para crear un nodo ROS 2
class EffectorPose(Node):
    def __init__(self):
        # Inicializa el nodo con el nombre 'effector_pose'
        super().__init__('effector_pose')

        # Crea un buffer donde se almacenan las transformaciones
        self.tf_buffer = Buffer()

        # Crea un listener que va llenando el buffer automáticamente con los datos de /tf
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Crea un temporizador que llama a la función lookup_pose cada 0.5 segundos
        self.timer = self.create_timer(0.5, self.lookup_pose)

    # Esta función se llama periódicamente para obtener la pose del efector
    def lookup_pose(self):
        try:
            # Busca la transformación desde 'base_link' hasta 'efector_link'
            # El tiempo es "now", es decir, la transformación más reciente disponible
            t = self.tf_buffer.lookup_transform(
                'base_link',        # Frame de referencia (padre)
                'efector_link',     # Frame hijo (efector final)
                rclpy.time.Time())  # Tiempo: ahora

            # Extrae la posición y orientación de la transformación
            pos = t.transform.translation
            rot = t.transform.rotation

            # Imprime por consola (logger) la pose actual del efector
            self.get_logger().info(
                f"Pose: x={pos.x:.2f}, y={pos.y:.2f}, z={pos.z:.2f} | "
                f"q=({rot.x:.2f}, {rot.y:.2f}, {rot.z:.2f}, {rot.w:.2f})"
            )

        except Exception as e:
            # Si ocurre algún error (ej. aún no existe la transformación), lo muestra como advertencia
            self.get_logger().warn(f"No transform: {e}")

# Función principal que lanza el nodo
def main(args=None):
    rclpy.init(args=args)          # Inicializa el sistema ROS 2
    node = EffectorPose()          # Crea una instancia del nodo
    rclpy.spin(node)               # Mantiene el nodo activo procesando eventos
    rclpy.shutdown()