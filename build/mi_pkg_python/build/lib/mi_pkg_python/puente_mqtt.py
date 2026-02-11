import rclpy
from rclpy.node import Node
from rclpy.duration import Duration

from std_msgs.msg import Float32, Int32

import paho.mqtt.client as mqtt
import json

class MQTTBridge(Node):
    def __init__(self):
        super().__init__('mqtt_bridge')

        self.pub = self.create_publisher(Float32, 'sensores', 1)
        self.subscription = self.create_subscription(Int32, 'acciones', self.listener_callback, 10)

        self.last_data = None
        self.active = True  # control de publicación activa
        self.last_mqtt_time = self.get_clock().now()

        self.timer = self.create_timer(0.1, self.publish_sensor_data)       # Publicador (10 Hz)
        self.timer_watchdog = self.create_timer(0.5, self.check_timeout)    # Verificador de tiempo

        self.topic_sub = "rm1/sensores"
        self.topic_pub = "rm1/acciones"
        self.mqtt_client = mqtt.Client()
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_message = self.on_message
        self.mqtt_client.connect("192.168.100.208", 1883, 60)
        self.mqtt_client.loop_start()

    def listener_callback(self, msg):
        payload = {
            "vel": {"u_meta": 0.34, "w_meta": 0.10},
            "avanzar": msg.data
        }
        msg_mqtt = json.dumps(payload)
        self.mqtt_client.publish(self.topic_pub, msg_mqtt)

    def on_connect(self, client, userdata, flags, rc):
        if rc == 0:
            print("Conectado al broker MQTT")
            client.subscribe(self.topic_sub)
        else:
            print(f"Error de conexión: código {rc}")

    def on_message(self, client, userdata, msg):
        try:
            mensaje = msg.payload.decode("utf-8")
            data = json.loads(mensaje)
            if msg.topic == self.topic_sub:
                self.last_data = float(data["EncoderI"])
                self.last_mqtt_time = self.get_clock().now()  # Actualiza tiempo del último dato
                self.active = True
        except Exception as e:
            print("Error procesando mensaje:", e)

    def publish_sensor_data(self):
        if self.last_data is not None and self.active:
            ros_msg = Float32()
            ros_msg.data = self.last_data
            self.pub.publish(ros_msg)
            self.get_logger().info(f"ROS2 publicó: {ros_msg.data}")

    def check_timeout(self):
        now = self.get_clock().now()
        if now - self.last_mqtt_time > Duration(seconds=2.0):
            if self.active:
                self.get_logger().warn("No se reciben datos desde MQTT. Se detiene la publicación.")
            self.active = False

def main(args=None):
    rclpy.init(args=args)
    node = MQTTBridge()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()