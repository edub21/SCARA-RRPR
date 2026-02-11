import cv2
from pupil_apriltags import Detector
import rclpy
from rclpy.node import Node
from avig_msg.msg import AprilTagPixel, AprilTagPixelArray
from sensor_msgs.msg import Image

from cv_bridge import CvBridge

class AprilTagPixelPublisher(Node):
      def __init__(self):
         super().__init__('apriltag_pixel_publisher')

         # Publicador para ID y coordenadas en píxeles (bruto)
         self.publisher_data = self.create_publisher(AprilTagPixelArray, 'apriltag_pixels', 1)
         # Publicador para imagen tipo image_raw
         self.publisher_image = self.create_publisher(Image, 'image_raw', 1)
         self.bridge = CvBridge()

         # Configurar cámara
         self.cap = cv2.VideoCapture(0)
         self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
         self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
         self.cap.set(cv2.CAP_PROP_FPS, 30)

         if not self.cap.isOpened():
            self.get_logger().error("No se pudo acceder a la cámara.")
            exit()

         # Configurar detector de AprilTags
         self.at_detector = Detector(families='tag36h11', nthreads=4)

         # Temporizador a 30 Hz
         self.timer = self.create_timer(1.0 / 30.0, self.timer_callback)
         self.get_logger().info("Nodo de detección AprilTag iniciado (modo simple sin calibración).")

      def timer_callback(self):
         ret, frame = self.cap.read()
         if not ret:
            self.get_logger().warn("No se pudo leer el frame.")
            return

         gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
         detections = self.at_detector.detect(gray)
         msg_arreglo = AprilTagPixelArray()

         for det in detections:
            tag_id = det.tag_id
            center_px = det.center  # coordenadas (x, y) en píxeles
            msg = AprilTagPixel()
            msg.id = tag_id
            msg.posx = float(center_px[0])
            msg.posy = float(center_px[1])
            msg_arreglo.tags.append(msg)

         self.publisher_data.publish(msg_arreglo)

         # Publicar la imagen como sensor_msgs/Image
         img_msg = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
         self.publisher_image.publish(img_msg)

      def destroy_node(self):
         self.cap.release()
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