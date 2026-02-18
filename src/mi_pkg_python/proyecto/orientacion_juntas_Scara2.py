import cv2
import numpy as np
import yaml
import rclpy
import math
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Int32 
from avig_msg.msg import ObjDetect 
from scipy.spatial.transform import Rotation as R
from pupil_apriltags import Detector

class AprilTagToROS2(Node):
    def __init__(self):
        super().__init__('apriltag_to_ros2')
        
        # --- PUBLICADORES ---
        self.pub_r1 = self.create_publisher(JointState, 'r1/joint_states', 10)
        self.pub_r2 = self.create_publisher(JointState, 'r2/joint_states', 10)
        self.pub_objects = self.create_publisher(ObjDetect, '/detected_objects', 10)
        self.pub_trigger = self.create_publisher(Int32, '/sistema/trigger', 10)

        # --- NUEVOS VALORES PROMEDIADOS ACTUALIZADOS (TAG ID 2) ---
        # Basados en tus últimos logs (Centro aprox [192.9, 145.2])
        self.default_tag_2_corners = np.array([
            [227.905, 182.608], # Promedio Esquina 0
            [230.235, 110.952], # Promedio Esquina 1
            [157.391, 107.123], # Promedio Esquina 2
            [155.688, 179.563]  # Promedio Esquina 3
        ], dtype=np.float32)

        # --- CONFIGURACIÓN DE ZONAS Y TOLERANCIAS ---
        self.distancia_tolerancia = 2.0 
        self.zona_r1 = {'x': -12.0, 'y': 51.0} 
        self.zona_r2 = {'x':  15, 'y': 30.0}

        # --- CARGA DE CALIBRACIÓN ---
        try:
            with open("/home/edub/ros2_ws/src/mi_pkg_python/proyecto/camera_calibrationJason.yaml", 'r') as f:
                calib_data = yaml.safe_load(f)
            self.K = np.array(calib_data['camera_matrix']['data']).reshape(3, 3)
            self.dist = np.array(calib_data['distortion_coefficients']['data'])
        except Exception as e:
            self.get_logger().error(f"Error cargando calibración: {e}")
            self.K = np.eye(3)
            self.dist = np.zeros(5)

        # --- DETECTOR Y FILTROS ---
        self.at_detector = Detector(families='tag36h11')
        self.tag_size_base = 0.045 # 4.5 cm (piezas)
        self.tag_size_large = 0.10 # 10 cm (bases robots)
        
        self.tag_history = {}
        self.history_size = 3 
        
        self.get_logger().info("Nodo AprilTag iniciado: Tag 2 promediado con NUEVOS VALORES.")

    class MockTag:
        def __init__(self, tag_id, R_mat, t_vec):
            self.tag_id = tag_id
            self.pose_R = R_mat
            self.pose_t = t_vec

    def smooth_pose(self, tag_id, R_mat, t_vec):
        if tag_id not in self.tag_history:
            self.tag_history[tag_id] = {'t': [], 'r_euler': []}
            
        self.tag_history[tag_id]['t'].append(t_vec)
        if len(self.tag_history[tag_id]['t']) > self.history_size:
            self.tag_history[tag_id]['t'].pop(0)
            
        r = R.from_matrix(R_mat)
        euler = r.as_euler('xyz')
        self.tag_history[tag_id]['r_euler'].append(euler)
        if len(self.tag_history[tag_id]['r_euler']) > self.history_size:
            self.tag_history[tag_id]['r_euler'].pop(0)
            
        avg_t = np.mean(self.tag_history[tag_id]['t'], axis=0)
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
        target = self.zona_r1 if base_id == 1 else self.zona_r2
        dist_error = math.sqrt((x_cm - target['x'])**2 + (y_cm - target['y'])**2)
        if dist_error <= self.distancia_tolerancia:
            msg = Int32()
            msg.data = base_id
            self.pub_trigger.publish(msg)

    def process_and_publish_object(self, base_id, tag_obj, tag_dict):
        if base_id not in tag_dict: return
        T_rel = self.get_relative_transform(tag_dict[base_id], tag_obj)
        x_cm, y_cm = T_rel[0, 3] * 100, T_rel[1, 3] * 100
        distancia = math.sqrt(x_cm**2 + y_cm**2)
        orientacion = self.get_yaw_diff(T_rel) 

        msg = ObjDetect()
        msg.id, msg.posx, msg.posy = int(tag_obj.tag_id), float(x_cm), float(y_cm)
        msg.orden, msg.dist, msg.orient = int((tag_obj.tag_id % 10) + 1), float(distancia), float(orientacion)
        #print(f"x = {x_cm}, y = {y_cm}")
        self.pub_objects.publish(msg)
        self.check_and_trigger_zone(base_id, x_cm, y_cm)
        

    def solve_tag_pose(self, corners, size):
        s = size / 2.0
        obj_pts = np.array([[-s, s, 0], [s, s, 0], [s, -s, 0], [-s, -s, 0]], dtype=np.float32)
        _, rvec, tvec = cv2.solvePnP(obj_pts, corners.astype(np.float32), self.K, self.dist)
        rmat, _ = cv2.Rodrigues(rvec)
        return rmat, tvec

    def process_frame(self, frame):
        h, w = frame.shape[:2]
        newcameramtx, _ = cv2.getOptimalNewCameraMatrix(self.K, self.dist, (w, h), 1, (w, h))
        undistorted = cv2.undistort(frame, self.K, self.dist, None, newcameramtx)
        gray = cv2.cvtColor(undistorted, cv2.COLOR_BGR2GRAY)

        detected_tags = self.at_detector.detect(gray, estimate_tag_pose=True,
            camera_params=(self.K[0, 0], self.K[1, 1], self.K[0, 2], self.K[1, 2]),
            tag_size=self.tag_size_base)

        tag_dict = {tag.tag_id: tag for tag in detected_tags}

        # --- FALLBACK PARA TAG ID 2 ---
        if 2 not in tag_dict:
            r_def, t_def = self.solve_tag_pose(self.default_tag_2_corners, self.tag_size_large)
            tag_dict[2] = self.MockTag(2, r_def, t_def)
            cv2.polylines(undistorted, [self.default_tag_2_corners.astype(np.int32)], True, (0, 0, 255), 1)

        escala_compensacion = self.tag_size_large / self.tag_size_base
        
        for tid, tag in tag_dict.items():
            if tid in [1, 2] and not isinstance(tag, self.MockTag):
                tag.pose_t = tag.pose_t * escala_compensacion
            tag.pose_R, tag.pose_t = self.smooth_pose(tid, tag.pose_R, tag.pose_t)

        for tid, tag in tag_dict.items():
            rvec, _ = cv2.Rodrigues(tag.pose_R)
            cv2.drawFrameAxes(undistorted, self.K, self.dist, rvec, tag.pose_t, 0.08 if tid in [1, 2] else 0.03)
            if 30 <= tid < 40: self.process_and_publish_object(1, tag, tag_dict)
            if 40 <= tid < 50: self.process_and_publish_object(2, tag, tag_dict)

        # --- ARTICULACIONES R1 ---
        if 1 in tag_dict:
            js1 = JointState()
            js1.header.stamp = self.get_clock().now().to_msg()
            
            if 11 in tag_dict:
                T_11_1 = self.get_relative_transform(tag_dict[1], tag_dict[11])
                yaw1 = self.get_yaw_diff(T_11_1)
                js1.name.append('r1_brazo_joint')
                js1.position.append(float(-yaw1))
                
                # Impresión de la primera articulación
                print(f"[R1] Brazo (1->11): {((yaw1)*180/3.1415):.2f}°")

                if 12 in tag_dict:
                    T_12_1 = self.get_relative_transform(tag_dict[11], tag_dict[12])
                    yaw2 = self.get_yaw_diff(T_12_1)
                    js1.name.extend(['r1_antebrazo_joint', 'r1_efector_joint'])
                    js1.position.extend([float(-yaw2), float(T_12_1[2, 3] + 0.1)])
                    
                    # Impresión de la segunda articulación
                    print(f"[R1] Antebrazo (11->12): {((yaw2)*180/3.1415):.2f}°")
            
            if js1.name: self.pub_r1.publish(js1)

        # --- ARTICULACIONES R2 ---
        if 2 in tag_dict:
            js2 = JointState()
            js2.header.stamp = self.get_clock().now().to_msg()
            
            if 21 in tag_dict:
                T_21_2 = self.get_relative_transform(tag_dict[2], tag_dict[21])
                yaw1_r2 = self.get_yaw_diff(T_21_2)
                js2.name.append('r2_brazo_joint')
                js2.position.append(float(-yaw1_r2))
                
                print(f"[R2] Brazo (2->21): {((yaw1_r2)*180/3.1415):.2f}°")

                if 22 in tag_dict:
                    T_22_2 = self.get_relative_transform(tag_dict[21], tag_dict[22])
                    yaw2_r2 = self.get_yaw_diff(T_22_2)
                    js2.name.extend(['r2_antebrazo_joint', 'r2_efector_joint'])
                    js2.position.extend([float(-yaw2_r2), float(T_22_2[2, 3])])
                    
                    print(f"[R2] Antebrazo (21->22): {((yaw2_r2)*180/3.1415):.2f}°")
            
            if js2.name: self.pub_r2.publish(js2)
            
        return undistorted

def main():
    rclpy.init()
    node = AprilTagToROS2()
    cap = cv2.VideoCapture(2) 
    cap.set(cv2.CAP_PROP_AUTOFOCUS, 0)
    cap.set(cv2.CAP_PROP_FOCUS, 25)
    
    try:
        while rclpy.ok():
            ret, frame = cap.read()
            if not ret: break
            out = node.process_frame(cv2.convertScaleAbs(frame, alpha=1.0, beta=-100))
            cv2.imshow("Deteccion Robots - Tag 2 Default Activo", out)
            if cv2.waitKey(1) & 0xFF == ord('q'): break
    finally:
        cap.release()
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()