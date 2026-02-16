import cv2
import numpy as np
import yaml
import rclpy
import math
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Int32 
# IMPORTANTE: Cambia 'mi_pkg_interfaces' por el nombre real de tu paquete de mensajes
from avig_msg.msg import ObjDetect 
from scipy.spatial.transform import Rotation as R
from pupil_apriltags import Detector

class AprilTagToROS2(Node):
    def __init__(self):
        super().__init__('apriltag_to_ros2')
        
        self.pub_r1 = self.create_publisher(JointState, 'r1/joint_states', 10)
        self.pub_r2 = self.create_publisher(JointState, 'r2/joint_states', 10)
        self.pub_objects = self.create_publisher(ObjDetect, '/detected_objects', 10)
        self.pub_trigger = self.create_publisher(Int32, '/sistema/trigger', 10)

        self.distancia_tolerancia = 4.0 
        self.zona_r1 = {'x': -0 , 'y': 51.0} 
        self.zona_r2 = {'x': -2 , 'y': 53.0}

        try:
            with open("/home/edub/ros2_ws/src/mi_pkg_python/proyecto/camera_calibration.yaml", 'r') as f:
                calib_data = yaml.safe_load(f)
            self.K = np.array(calib_data['camera_matrix']['data']).reshape(3, 3)
            self.dist = np.array(calib_data['distortion_coefficients']['data'])
        except Exception as e:
            self.get_logger().error(f"Error cargando calibración: {e}")
            self.K = np.eye(3)
            self.dist = np.zeros(5)

        self.at_detector = Detector(families='tag36h11')
        self.tag_size_base = 0.045 # 4.5 cm para la mayoría de tags
        self.tag_size_large = 0.10 # 10 cm para las bases de los robots
        
        # --- NUEVO: Configuración del filtro de promedio (Media Móvil) ---
        self.tag_history = {}
        self.history_size = 3  # Promedio de las últimas 3 tomas
        
        self.get_logger().info("Nodo AprilTag -> ROS 2 iniciado con suavizado de 3 frames")

    # --- NUEVO: Función para promediar poses ---
    def smooth_pose(self, tag_id, R_mat, t_vec):
        if tag_id not in self.tag_history:
            self.tag_history[tag_id] = {'t': [], 'r_euler': []}
            
        # 1. Guardar y limitar historial de Traslación
        self.tag_history[tag_id]['t'].append(t_vec)
        if len(self.tag_history[tag_id]['t']) > self.history_size:
            self.tag_history[tag_id]['t'].pop(0)
            
        # 2. Guardar y limitar historial de Rotación (convertido a Euler para promediar)
        r = R.from_matrix(R_mat)
        euler = r.as_euler('xyz')
        self.tag_history[tag_id]['r_euler'].append(euler)
        if len(self.tag_history[tag_id]['r_euler']) > self.history_size:
            self.tag_history[tag_id]['r_euler'].pop(0)
            
        # 3. Calcular Promedio de Traslación
        avg_t = np.mean(self.tag_history[tag_id]['t'], axis=0)
        
        # 4. Calcular Promedio Circular de Rotación (evita errores en saltos de +-180 grados)
        eulers = np.array(self.tag_history[tag_id]['r_euler'])
        avg_euler = np.arctan2(np.mean(np.sin(eulers), axis=0), np.mean(np.cos(eulers), axis=0))
        avg_R = R.from_euler('xyz', avg_euler).as_matrix()
        
        return avg_R, avg_t

    def get_relative_transform(self, tag_base, tag_child):
        T_base = np.eye(4)
        T_base[:3, :3] = tag_base.pose_R
        T_base[:3, 3] = tag_base.pose_t.flatten()

        T_child = np.eye(4)
        T_child[:3, :3] = tag_child.pose_R
        T_child[:3, 3] = tag_child.pose_t.flatten()

        return np.linalg.inv(T_base) @ T_child

    def get_yaw_diff(self, T_rel):
        r = R.from_matrix(T_rel[:3, :3])
        return r.as_euler('xyz')[2]

    def check_and_trigger_zone(self, base_id, x_cm, y_cm):
        target = None
        if base_id == 1:
            target = self.zona_r1
            trigger_code = 1
        elif base_id == 2:
            target = self.zona_r2
            trigger_code = 2
            
        if target:
            dist_error = math.sqrt((x_cm - target['x'])**2 + (y_cm - target['y'])**2)
            if dist_error <= self.distancia_tolerancia:
                msg = Int32()
                msg.data = trigger_code
                self.pub_trigger.publish(msg)

    def process_and_publish_object(self, base_id, tag_obj, tag_dict, check_trigger=True):
        if base_id not in tag_dict: return

        T_rel = self.get_relative_transform(tag_dict[base_id], tag_obj)
        x_cm = T_rel[0, 3] * 100
        y_cm = T_rel[1, 3] * 100
        distancia = math.sqrt(x_cm**2 + y_cm**2)
        orientacion = self.get_yaw_diff(T_rel) 
        orden_val = (tag_obj.tag_id % 10) + 1 

        msg = ObjDetect()
        msg.id = int(tag_obj.tag_id)
        msg.posx = float(x_cm)
        msg.posy = float(y_cm)
        msg.orden = int(orden_val)
        msg.dist = float(distancia)
        msg.orient = float(orientacion)
        
        self.pub_objects.publish(msg)

        if check_trigger:
            #print(f"x={x_cm:.2f}cm , y = {y_cm:.2f}cm")
            self.check_and_trigger_zone(base_id, x_cm, y_cm)

    def process_frame(self, frame):
        h, w = frame.shape[:2]
        newcameramtx, _ = cv2.getOptimalNewCameraMatrix(self.K, self.dist, (w, h), 1, (w, h))
        undistorted = cv2.undistort(frame, self.K, self.dist, None, newcameramtx)
        gray = cv2.cvtColor(undistorted, cv2.COLOR_BGR2GRAY)

        tags = self.at_detector.detect(
            gray, estimate_tag_pose=True,
            camera_params=(self.K[0, 0], self.K[1, 1], self.K[0, 2], self.K[1, 2]),
            tag_size=self.tag_size_base
        )

        escala_compensacion = self.tag_size_large / self.tag_size_base
        
        # --- APLICAMOS ESCALADO Y LUEGO SUAVIZADO ---
        for tag in tags:
            # Primero corregimos la escala de los tags grandes
            if tag.tag_id in [1, 2]:
                tag.pose_t = tag.pose_t * escala_compensacion
                
            # Luego aplicamos el filtro de promediado
            tag.pose_R, tag.pose_t = self.smooth_pose(tag.tag_id, tag.pose_R, tag.pose_t)

        tag_dict = {tag.tag_id: tag for tag in tags}
        
        for tag in tags:
            rvec, _ = cv2.Rodrigues(tag.pose_R)
            tvec = tag.pose_t
            
            axis_len = 0.08 if tag.tag_id in [1, 2] else 0.03
            cv2.drawFrameAxes(undistorted, self.K, self.dist, rvec, tvec, axis_len)
            
            corners = np.int32(tag.corners)
            cv2.polylines(undistorted, [corners], True, (0, 255, 0), 2)

            # --- LÓGICA DE DETECCIÓN DE OBJETOS ---
            if 30 <= tag.tag_id < 40:
                self.process_and_publish_object(1, tag, tag_dict, check_trigger=True)

            if 40 <= tag.tag_id < 50:
                self.process_and_publish_object(2, tag, tag_dict, check_trigger=True)

            # --- DETECCIÓN DE TAGS DE DESTINO (No disparan trigger) ---
            if tag.tag_id == 8:
                self.process_and_publish_object(1, tag, tag_dict, check_trigger=False)

            if tag.tag_id == 9:
                self.process_and_publish_object(2, tag, tag_dict, check_trigger=False)

        # --- LÓGICA ARTICULACIONES ROBOTS ---
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
                T_12_1 = self.get_relative_transform(tag_dict[11], tag_dict[12]) 
                z_diff = T_12_1[2, 3] + 0.1
                js1.name.extend(['r1_antebrazo_joint', 'r1_efector_joint'])
                js1.position.extend([float(-self.get_yaw_diff(T_12_1)), float(z_diff)])
                print(f"Distancia Z cruda: {T_12_1[2, 3]:.4f}")
                
            if js1.name: self.pub_r1.publish(js1)

        if 2 in tag_dict:
            js2 = JointState()
            js2.header.stamp = self.get_clock().now().to_msg()
            js2.name = []
            js2.position = []
            
            if 21 in tag_dict:
                T_21_2 = self.get_relative_transform(tag_dict[2], tag_dict[21])
                js2.name.append('r2_brazo_joint')
                js2.position.append(float(-self.get_yaw_diff(T_21_2)))

            if 22 in tag_dict and 21 in tag_dict:
                T_22_2 = self.get_relative_transform(tag_dict[21], tag_dict[22])
                z_diff = T_22_2[2, 3]
                js2.name.extend(['r2_antebrazo_joint', 'r2_efector_joint'])
                js2.position.extend([float(-self.get_yaw_diff(T_22_2)), float(z_diff)])
                

            if js2.name: self.pub_r2.publish(js2)

        return undistorted

def main():
    rclpy.init()
    node = AprilTagToROS2()
    cap = cv2.VideoCapture(0)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    alfa = 0.8; beta = -50

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