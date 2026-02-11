import cv2
import numpy as np
import yaml
import rclpy
import math
from rclpy.node import Node
from sensor_msgs.msg import JointState
# IMPORTANTE: Cambia 'mi_pkg_interfaces' por el nombre real de tu paquete de mensajes
from avig_msg.msg import ObjDetect 
from scipy.spatial.transform import Rotation as R
from pupil_apriltags import Detector

class AprilTagToROS2(Node):
    def __init__(self):
        super().__init__('apriltag_to_ros2')
        
        # Publicadores
        self.pub_r1 = self.create_publisher(JointState, 'r1/joint_states', 10)
        self.pub_r2 = self.create_publisher(JointState, 'r2/joint_states', 10)
        
        # CAMBIO: Publicador usando tu mensaje personalizado
        self.pub_objects = self.create_publisher(ObjDetect, '/detected_objects', 10)

        # Cargar parámetros (Asegúrate que la ruta sea correcta)
        with open("/home/edub/ros2_ws/src/mi_pkg_python/proyecto/camera_calibration.yaml", 'r') as f:
            calib_data = yaml.safe_load(f)
        self.K = np.array(calib_data['camera_matrix']['data']).reshape(3, 3)
        self.dist = np.array(calib_data['distortion_coefficients']['data'])

        self.at_detector = Detector(families='tag36h11')
        self.tag_size = 0.04 
        
        self.get_logger().info("Nodo AprilTag -> ROS 2 iniciado")

    def get_relative_transform(self, tag_base, tag_child):
        """Matriz de transformación de child respecto a base"""
        T_base = np.eye(4)
        T_base[:3, :3] = tag_base.pose_R
        T_base[:3, 3] = tag_base.pose_t.flatten()

        T_child = np.eye(4)
        T_child[:3, :3] = tag_child.pose_R
        T_child[:3, 3] = tag_child.pose_t.flatten()

        return np.linalg.inv(T_base) @ T_child

    def get_yaw_diff(self, T_rel):
        """Retorna ángulo Z (Yaw) en radianes"""
        r = R.from_matrix(T_rel[:3, :3])
        return r.as_euler('xyz')[2]

    def process_and_publish_object(self, base_id, tag_obj, tag_dict):
        """
        Calcula y publica los datos del objeto respecto a la base dada.
        """
        if base_id not in tag_dict: return

        # 1. Obtener Transformada Relativa
        T_rel = self.get_relative_transform(tag_dict[base_id], tag_obj)
        
        # 2. Extraer Posición (CM)
        x_cm = T_rel[0, 3] * 100
        y_cm = T_rel[1, 3] * 100
        
        # 3. Calcular Distancia Euclidiana (Pitágoras)
        distancia = math.sqrt(x_cm**2 + y_cm**2)

        # 4. Calcular Orientación (Yaw)
        orientacion = self.get_yaw_diff(T_rel) # En radianes

        # 5. Definir 'Orden' (Lógica de ejemplo: ID 30 -> 1, ID 31 -> 2...)
        # Ajusta esto según tu lógica de negocio
        orden_val = (tag_obj.tag_id % 10) + 1 

        # 6. Crear y Publicar Mensaje
        msg = ObjDetect()
        msg.id = int(tag_obj.tag_id)
        msg.posx = float(x_cm)
        msg.posy = float(y_cm)
        msg.orden = int(orden_val)
        msg.dist = float(distancia)
        msg.orient = float(orientacion)
        
        self.pub_objects.publish(msg)
        # Opcional: Debug en consola
        # print(f"Obj {msg.id}: X={x_cm:.1f} Y={y_cm:.1f} Dist={distancia:.1f}")

    def process_frame(self, frame):
        h, w = frame.shape[:2]
        newcameramtx, _ = cv2.getOptimalNewCameraMatrix(self.K, self.dist, (w, h), 1, (w, h))
        undistorted = cv2.undistort(frame, self.K, self.dist, None, newcameramtx)
        gray = cv2.cvtColor(undistorted, cv2.COLOR_BGR2GRAY)

        tags = self.at_detector.detect(
            gray, estimate_tag_pose=True,
            camera_params=(self.K[0, 0], self.K[1, 1], self.K[0, 2], self.K[1, 2]),
            tag_size=self.tag_size
        )

        tag_dict = {tag.tag_id: tag for tag in tags}
        
        # Dibujar
        for tag in tags:
            rvec, _ = cv2.Rodrigues(tag.pose_R)
            tvec = tag.pose_t
            cv2.drawFrameAxes(undistorted, self.K, self.dist, rvec, tvec, 0.03)
            corners = np.int32(tag.corners)
            cv2.polylines(undistorted, [corners], True, (0, 255, 0), 2)

            # --- LÓGICA DE DETECCIÓN DE OBJETOS (Corregida Indentación) ---
            
            # Objetos para Robot 1 (Base Tag 1) -> IDs 30-39
            if 30 <= tag.tag_id < 40:
                self.process_and_publish_object(1, tag, tag_dict)

            # Objetos para Robot 2 (Base Tag 2) -> IDs 40-49
            if 40 <= tag.tag_id < 50:
                self.process_and_publish_object(2, tag, tag_dict)

        # --- LÓGICA ARTICULACIONES ROBOTS (Se mantiene igual) ---
        
        # Robot 1
        if 1 in tag_dict:
            js1 = JointState()
            js1.header.stamp = self.get_clock().now().to_msg()
            js1.name = []
            js1.position = []
            
            if 11 in tag_dict:
                T_11_1 = self.get_relative_transform(tag_dict[1], tag_dict[11])
                js1.name.append('r1_brazo_joint')
                js1.position.append(float(-self.get_yaw_diff(T_11_1)))

            if 12 in tag_dict and 11 in tag_dict:
                T_12_1 = self.get_relative_transform(tag_dict[11], tag_dict[12]) # De 11 a 12
                # OJO: Tu lógica original usaba T_12_1 directo para Z. 
                # Si quieres Z respecto a base, necesitarías T_12_Base.
                # Dejo tu lógica original aquí:
                z_diff = T_12_1[2, 3] + 0.215
                js1.name.extend(['r1_antebrazo_joint', 'r1_efector_joint'])
                js1.position.extend([float(-self.get_yaw_diff(T_12_1)), float(z_diff)])
            
            if js1.name: self.pub_r1.publish(js1)

        # Robot 2
        if 2 in tag_dict:
            js2 = JointState()
            js2.header.stamp = self.get_clock().now().to_msg()
            js2.name = []
            js2.position = []
            
            if 21 in tag_dict:
                T_21_2 = self.get_relative_transform(tag_dict[2], tag_dict[21])
                js2.name.append('r2_brazo_joint')
                js2.position.append(float(self.get_yaw_diff(T_21_2)))

            if 22 in tag_dict and 21 in tag_dict:
                T_22_2 = self.get_relative_transform(tag_dict[21], tag_dict[22])
                z_diff = T_22_2[2, 3] - 0.15
                js2.name.extend(['r2_antebrazo_joint', 'r2_efector_joint'])
                js2.position.extend([float(self.get_yaw_diff(T_22_2)), float(z_diff)])

            if js2.name: self.pub_r2.publish(js2)

        return undistorted

def main():
    rclpy.init()
    node = AprilTagToROS2()
    cap = cv2.VideoCapture(0)
    alfa = 1; beta = 0# Ajuste brillo/contraste sugerido

    try:
        while rclpy.ok():
            ret, frame = cap.read()
            if not ret: break
            frame_ajustado = cv2.convertScaleAbs(frame, alpha=alfa, beta=beta)
            output_frame = node.process_frame(frame_ajustado)
            cv2.imshow("Deteccion Robots", output_frame)
            if cv2.waitKey(1) & 0xFF == ord('q'): break
    except KeyboardInterrupt: pass
    finally:
        cap.release()
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()