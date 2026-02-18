import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
from std_msgs.msg import ColorRGBA
from avig_msg.msg import ObjDetect  # Asegúrate de que este sea el paquete correcto de tus mensajes

class CuboPublisher(Node):
    def __init__(self):
        super().__init__('cubo_publisher')
        self.publisher = self.create_publisher(Marker, 'visualization_marker', 10)
        
        # Suscripción al tópico que procesa tu nodo de visión
        self.subscription = self.create_subscription(
            ObjDetect,
            '/detected_objects',
            self.listener_callback,
            10)
        
        # Diccionario para guardar el último estado de cada cubo detectado
        self.cubos_detectados = {}

        # Timer a 10Hz (0.1s) para actualizar RViz de forma fluida
        self.timer = self.create_timer(0.1, self.publicar_cubos)

    def listener_callback(self, msg):
        # Guardamos el mensaje usando el ID combinado (ej. 135)
        self.cubos_detectados[msg.id] = msg

    def publicar_cubos(self):
        # Recorremos todos los cubos detectados
        for combined_id, info in list(self.cubos_detectados.items()):
            
            # Extraemos la base y el ID real del tag
            base_id = combined_id // 100  # 1 (SCARA 1) o 2 (SCARA 2)
            tag_id = combined_id % 100    # Número del tag (ej. 35)
            
            # Clasificamos solo los tags del 30 al 49
            if 30 <= tag_id <= 49:
                cubo = Marker()
                
                # Asignamos el frame de referencia al SCARA correcto
                if base_id == 1:
                    cubo.header.frame_id = 'r1_base_link'
                elif base_id == 2:
                    cubo.header.frame_id = 'r2_base_link'
                else:
                    continue
                    
                cubo.header.stamp = self.get_clock().now().to_msg()
                cubo.ns = 'cubos_banda'
                cubo.id = combined_id
                cubo.type = Marker.CUBE
                cubo.action = Marker.ADD
                
                # --- CALIBRACIÓN DE EJES Y OFFSETS ---
                # Pasamos de centímetros a metros
                medida_x_m = info.posx / 100.0
                medida_y_m = info.posy / 100.0
                
                # Ajusta estos valores si los cubos aparecen movidos respecto a tu cámara real
                offset_x = 0.0   # Mueve el cubo a la izquierda/derecha a lo largo de la banda
                offset_y = 0.00  # Mueve el cubo hacia adelante para que caiga justo sobre la banda
                
                # Dependiendo de tu cámara, tal vez necesites cambiar el signo a negativo (-) 
                # en alguna de estas variables si el cubo se mueve al lado contrario en RViz.
                cubo.pose.position.x = medida_y_m + offset_x
                cubo.pose.position.y = medida_x_m + offset_y
                cubo.pose.position.z = 0.01  # Altura (mitad de los 5cm) para que repose en la banda
                
                # Orientación (aprovechando el cálculo de OpenCV)
                cubo.pose.orientation.x = 0.0
                cubo.pose.orientation.y = 0.0
                cubo.pose.orientation.z = info.orient
                cubo.pose.orientation.w = 1.0 
                
                # Tamaño visual del cubo (5 x 5 x 5 cm)
                cubo.scale.x = 0.05
                cubo.scale.y = 0.04
                cubo.scale.z = 0.12
                
                # Colores según el rango
                if 30 <= tag_id <= 39:
                    cubo.color = ColorRGBA(r=1.0, g=0.0, b=0.0, a=0.9)  # VERDE
                elif 40 <= tag_id <= 49:
                    cubo.color = ColorRGBA(r=0.0, g=1.0, b=0.0, a=0.9)  # ROJO
                    
                # Desaparece si la cámara deja de verlo por medio segundo
                cubo.lifetime.sec = 0
                cubo.lifetime.nanosec = 500000000 
                
                self.publisher.publish(cubo)
                
        # Limpiamos el diccionario para evitar que se queden fijos cuando no se ven
        self.cubos_detectados.clear()

def main(args=None):
    rclpy.init(args=args)
    node = CuboPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()