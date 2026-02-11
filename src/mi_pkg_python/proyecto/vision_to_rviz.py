import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
import cv2
import numpy as np
import yaml
import math
from pupil_apriltags import Detector
# scipy no se usa explícitamente en este flujo simplificado, pero lo dejo por si acaso
from scipy.spatial.transform import Rotation as R 

class VisionControlNode(Node):
    def __init__(self):
        super().__init__('vision_control_node')

        # --- Publicadores ROS 2 ---
        self.pub_r1 = self.create_publisher(JointState, 'r1/joint_states', 10)
        self.pub_r2 = self.create_publisher(JointState, 'r2/joint_states', 10)

        # --- Cargar Calibración ---
        # NOTA: Si no tienes el archivo, la medición de profundidad (Z) será errónea.
        try:
            with open("camera_calibration.yaml", 'r') as f:
                calib_data = yaml.safe_load(f)
                self.K = np.array(calib_data['camera_matrix']['data']).reshape(3, 3)
                self.dist = np.array(calib_data['distortion_coefficients']['data'])
                self.get_logger().info("Calibración cargada correctamente.")
        except FileNotFoundError:
            self.get_logger().warn("No se encontró 'camera_calibration.yaml'. Usando valores dummy.")
            self.K = np.array([[800, 0, 320], [0, 800, 240], [0, 0, 1]], dtype=float)
            self.dist = np.zeros(5)

        # --- Configuración Detector ---
        self.at_detector = Detector(families='tag36h11')
        self.tag_size = 0.04  # 40mm

        # --- Iniciar Cámara ---
        self.cap = cv2.VideoCapture(0) # Cambia a 2, 4, etc. si usas cámara externa
        if not self.cap.isOpened():
            self.get_logger().error("No se pudo abrir la cámara.")

        # --- Timer (30 FPS) ---
        self.timer = self.create_timer(0.033, self.process_frame)

    def get_transform_matrix(self, tag_detection):
        """Convierte la detección del tag en una matriz 4x4 homogénea"""
        rot = tag_detection.pose_R
        trans = tag_detection.pose_t.reshape(3, 1)
        T = np.hstack([rot, trans])
        T = np.vstack([T, [0, 0, 0, 1]])
        return T

    def process_frame(self):
        ret, frame = self.cap.read()
        if not ret:
            return

        # 1. Corregir distorsión
        h, w = frame.shape[:2]
        newcameramtx, _ = cv2.getOptimalNewCameraMatrix(self.K, self.dist, (w, h), 1, (w, h))
        undistorted = cv2.undistort(frame, self.K, self.dist, None, newcameramtx)
        
        # 2. Detección
        gray = cv2.cvtColor(undistorted, cv2.COLOR_BGR2GRAY)
        
        # Detección de tags
        tags = self.at_detector.detect(
            gray,
            estimate_tag_pose=True,
            camera_params=(self.K[0, 0], self.K[1, 1], self.K[0, 2], self.K[1, 2]),
            tag_size=self.tag_size
        )

        transforms = {}    # Guardar Matrices
        centers = {}       # Guardar Centros (para dibujar)

        # 3. Procesar detecciones y dibujar
        for tag in tags:
            tag_id = tag.tag_id
            
            # CORRECCION 1: Usar el nombre correcto del método
            transforms[tag_id] = self.get_transform_matrix(tag)
            
            center = tuple(np.mean(tag.corners, axis=0).astype(int))
            centers[tag_id] = center

            # Dibujo visual
            corners = np.int32(tag.corners)
            cv2.polylines(undistorted, [corners], True, (0, 255, 0), 2)
            cv2.putText(undistorted, f"ID:{tag_id}", center, 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)

        # --- Lógica ROBOT 1 (Base: 1, Codo: 11, Efector: 12) ---
        if all(k in transforms for k in [1, 11, 12]):
            try:
                # Todo relativo a la Base (Tag 1)
                T1_inv = np.linalg.inv(transforms[1])
                
                # Calcular posiciones cartesianas relativas
                p11 = (T1_inv @ transforms[11])[:3, 3] # Codo
                p12 = (T1_inv @ transforms[12])[:3, 3] # Efector

                # IK Geométrico SCARA
                q1 = math.atan2(p11[1], p11[0])

                vec_antebrazo = p12 - p11
                q2_abs = math.atan2(vec_antebrazo[1], vec_antebrazo[0])
                q2 = q2_abs - q1
                
                # Altura Z (Invertida o ajustada según tu setup)
                q3 = p12[2] 

                # CORRECCION 2 y 3: Calcular antes de enviar y usar el nombre correcto
                self.publish_joint_state(self.pub_r1, 'r1', [q1, q2, q3])
                
                # Dibujar esqueleto R1
                if 1 in centers and 11 in centers:
                    cv2.line(undistorted, centers[1], centers[11], (0, 0, 255), 2)
                if 11 in centers and 12 in centers:
                    cv2.line(undistorted, centers[11], centers[12], (0, 0, 255), 2)

            except Exception as e:
                self.get_logger().warn(f"Error mate R1: {e}")

        # --- Lógica ROBOT 2 (Base: 2, Codo: 21, Efector: 22) ---
        if all(k in transforms for k in [2, 21, 22]):
            try:
                T2_inv = np.linalg.inv(transforms[2])
                p21 = (T2_inv @ transforms[21])[:3, 3]
                p22 = (T2_inv @ transforms[22])[:3, 3]

                q1 = math.atan2(p21[1], p21[0])
                
                vec_antebrazo = p22 - p21
                q2_abs = math.atan2(vec_antebrazo[1], vec_antebrazo[0])
                q2 = q2_abs - q1
                
                q3 = p22[2]

                self.publish_joint_state(self.pub_r2, 'r2', [q1, q2, q3])

                # Dibujar esqueleto R2
                if 2 in centers and 21 in centers:
                    cv2.line(undistorted, centers[2], centers[21], (255, 255, 0), 2)
                if 21 in centers and 22 in centers:
                    cv2.line(undistorted, centers[21], centers[22], (255, 255, 0), 2)

            except Exception as e:
                self.get_logger().warn(f"Error mate R2: {e}")

        # Mostrar imagen
        cv2.imshow("Vision SCARA Digital Twin", undistorted)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            self.cap.release()
            cv2.destroyAllWindows()
            self.destroy_node()
            rclpy.shutdown()

    def publish_joint_state(self, publisher, prefix, positions):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        # Nombres de las juntas según tu URDF
        msg.name = [f'{prefix}_brazo_joint', f'{prefix}_antebrazo_joint', f'{prefix}_efector_joint']
        msg.position = [float(p) for p in positions]
        publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = VisionControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if node.cap.isOpened():
            node.cap.release()
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()