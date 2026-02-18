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
        
        self.pub_r1 = self.create_publisher(JointState, 'r1/joint_states', 10)
        self.pub_r2 = self.create_publisher(JointState, 'r2/joint_states', 10)
        self.pub_objects = self.create_publisher(ObjDetect, '/detected_objects', 10)
        self.pub_trigger = self.create_publisher(Int32, '/sistema/trigger', 10)

        # Estos son los valores que podrías actualizar con lo que salga en el print
        self.default_tag_1_corners = np.array([
            [935.34, 436.71], [928.67, 496.53],
            [990.99, 497.95], [998.39, 437.29]
        ], dtype=np.float32)

        self.distancia_tolerancia = 2.0 
        self.zona_r1 = {'x': 8.0, 'y': 58.3} 
        self.zona_r2 = {'x': 0.0, 'y': 51.0}

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
        self.tag_size_base = 0.045 
        self.tag_size_large = 0.10 
        self.tag_history = {}
        self.history_size = 3 

    class MockTag:
        def __init__(self, tag_id, R_mat, t_vec):
            self.tag_id = tag_id
            self.pose_R = R_mat
            self.pose_t = t_vec

    def solve_tag_pose(self, corners, size):
        s = size / 2.0
        obj_pts = np.array([[-s, s, 0], [s, s, 0], [s, -s, 0], [-s, -s, 0]], dtype=np.float32)
        _, rvec, tvec = cv2.solvePnP(obj_pts, corners.astype(np.float32), self.K, self.dist)
        rmat, _ = cv2.Rodrigues(rvec)
        return rmat, tvec

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
        T_base = np.eye(4); T_base[:3, :3] = tag_base.pose_R; T_base[:3, 3] = tag_base.pose_t.flatten()
        T_child = np.eye(4); T_child[:3, :3] = tag_child.pose_R; T_child[:3, 3] = tag_child.pose_t.flatten()
        return np.linalg.inv(T_base) @ T_child

    def get_yaw_diff(self, T_rel):
        return R.from_matrix(T_rel[:3, :3]).as_euler('xyz')[2]

    def process_and_publish_object(self, base_id, tag_obj, tag_dict, check_trigger=True):
        if base_id not in tag_dict: return
        T_rel = self.get_relative_transform(tag_dict[base_id], tag_obj)
        x_cm, y_cm = T_rel[0, 3] * 100, T_rel[1, 3] * 100
        distancia = math.sqrt(x_cm**2 + y_cm**2)
        orientacion = self.get_yaw_diff(T_rel) 
        msg = ObjDetect()
        msg.id = int(base_id * 100 + tag_obj.tag_id)
        msg.posx, msg.posy = float(x_cm), float(y_cm)
        msg.orden, msg.dist, msg.orient = int((tag_obj.tag_id % 10) + 1), float(distancia), float(orientacion)
        self.pub_objects.publish(msg)
        if check_trigger:
            target = self.zona_r1 if base_id == 1 else self.zona_r2
            dist_err = math.sqrt((x_cm - target['x'])**2 + (y_cm - target['y'])**2)
            if dist_err <= self.distancia_tolerancia:
                t_msg = Int32(); t_msg.data = msg.id; self.pub_trigger.publish(t_msg)

    def process_frame(self, frame):
        h, w = frame.shape[:2]
        newcameramtx, _ = cv2.getOptimalNewCameraMatrix(self.K, self.dist, (w, h), 1, (w, h))
        undistorted = cv2.undistort(frame, self.K, self.dist, None, newcameramtx)
        gray = cv2.cvtColor(undistorted, cv2.COLOR_BGR2GRAY)

        tags = self.at_detector.detect(gray, estimate_tag_pose=True, 
                                       camera_params=(self.K[0,0], self.K[1,1], self.K[0,2], self.K[1,2]), 
                                       tag_size=self.tag_size_base)

        tag_dict = {tag.tag_id: tag for tag in tags}
        
        # --- BLOQUE PARA IMPRIMIR ESQUINAS DEL TAG 1 ---
        if 1 in tag_dict:
            c = tag_dict[1].corners
            print("\n[!] TAG 1 DETECTADO - ESQUINAS (CORNERS):")
            print(f"np.array([")
            print(f"    [{c[0][0]:.8f}, {c[0][1]:.8f}],")
            print(f"    [{c[1][0]:.8f}, {c[1][1]:.8f}],")
            print(f"    [{c[2][0]:.8f}, {c[2][1]:.8f}],")
            print(f"    [{c[3][0]:.8f}, {c[3][1]:.8f}]")
            print(f"], dtype=np.float32)")
        # ----------------------------------------------

        escala_compensacion = self.tag_size_large / self.tag_size_base

        if 1 not in tag_dict:
            r1, t1 = self.solve_tag_pose(self.default_tag_1_corners, self.tag_size_large)
            tag_dict[1] = self.MockTag(1, r1, t1)
            cv2.polylines(undistorted, [self.default_tag_1_corners.astype(np.int32)], True, (0, 0, 255), 2)

        for tid, tag in tag_dict.items():
            if tid in [1, 2] and not isinstance(tag, self.MockTag):
                tag.pose_t = tag.pose_t * escala_compensacion
            tag.pose_R, tag.pose_t = self.smooth_pose(tid, tag.pose_R, tag.pose_t)

        for tid, tag in tag_dict.items():
            rvec, _ = cv2.Rodrigues(tag.pose_R)
            cv2.drawFrameAxes(undistorted, self.K, self.dist, rvec, tag.pose_t, 0.05)
            if (30 <= tid < 50) or tid in [8, 9]:
                self.process_and_publish_object(1, tag, tag_dict, check_trigger=(tid not in [8, 9]))
                self.process_and_publish_object(2, tag, tag_dict, check_trigger=(tid not in [8, 9]))

        return undistorted

def main():
    rclpy.init()
    node = AprilTagToROS2()
    cap = cv2.VideoCapture(1) # Asegúrate de que el índice sea el correcto
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    
    try:
        while rclpy.ok():
            ret, frame = cap.read()
            if not ret: break
            # He quitado el scaleAbs para ver la imagen natural y facilitar la lectura de esquinas
            out = node.process_frame(frame)
            cv2.imshow("Deteccion - Modo Calibracion Esquines", out)
            if cv2.waitKey(1) & 0xFF == ord('q'): break
    finally:
        cap.release()
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__': main()