import cv2
from pupil_apriltags import Detector
import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from avig_msg.msg import AprilTagPixel, AprilTagPixelArray

class AprilTagPixelPublisher(Node):
      def __init__(self):
         super().__init__('apriltag_pixel_publisher')

         self.publisher_data = self.create_publisher(AprilTagPixelArray, 'apriltag_pixels_arreglo', 1)

         self.cap = cv2.VideoCapture(0)
         self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
         self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
         self.cap.set(cv2.CAP_PROP_FPS, 30)

         if not self.cap.isOpened():
            self.get_logger().error("No se pudo acceder a la cámara.")
            exit()

         self.at_detector = Detector(families='tag36h11', nthreads=4)

         # Crear ventana redimensionable (solo si se usa visualización)
         cv2.namedWindow("AprilTag View", cv2.WINDOW_NORMAL)
         cv2.resizeWindow("AprilTag View", 800, 600)

         self.timer = self.create_timer(1.0 / 30.0, self.timer_callback)
         self.get_logger().info("Nodo AprilTag iniciado.")

      def timer_callback(self):
         ret, frame = self.cap.read()
         if not ret:
            self.get_logger().warn(" No se pudo leer el frame.")
            return

         gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
         detections = self.at_detector.detect(gray)

         msg_arreglo = AprilTagPixelArray()
         for det in detections:
            tag_id = det.tag_id
            center_px = det.center
            
            msg = AprilTagPixel()
            msg.id = tag_id
            msg.posx = float(center_px[0])
            msg.posy = float(center_px[1])
            msg_arreglo.tags.append(msg)
         self.publisher_data.publish(msg_arreglo)
         # Visualizacion
         self.visualizar_detecciones(frame, detections)

      def visualizar_detecciones(self, frame, detections):
         """Muestra la imagen con círculos e ID de tags detectados."""
         for det in detections:
            center = (int(det.center[0]), int(det.center[1]))
            cv2.circle(frame, center, 8, (0, 255, 0), 2)
            cv2.putText(frame, f"ID:{det.tag_id}", (center[0] + 10, center[1] - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 0, 0), 2)

         cv2.imshow("AprilTag View", frame)
         if cv2.waitKey(1) & 0xFF == ord('q'):
            self.get_logger().info(" 'q' presionado. Saliendo.")
            self.cap.release()
            cv2.destroyAllWindows()
            rclpy.shutdown()

      def destroy_node(self):
         self.cap.release()
         cv2.destroyAllWindows()
         super().destroy_node()

def main(args=None):
      rclpy.init(args=args)
      node = AprilTagPixelPublisher()
      try:
         rclpy.spin(node)
      except KeyboardInterrupt:
         node.destroy_node()
         rclpy.shutdown()

if __name__ == '__main__':
      main()