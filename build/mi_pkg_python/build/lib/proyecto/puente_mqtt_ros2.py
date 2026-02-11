import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
from std_msgs.msg import Float32MultiArray,UInt8
from sensor_msgs.msg import JointState

import paho.mqtt.client as mqtt
import json
import math


class MQTTBridge(Node):
    def __init__(self):
        super().__init__('mqtt_bridge_proyecto')

        # ROS publishers (gemelos digitales)
        self.publisher_r1 = self.create_publisher(JointState, 'r1/joint_states', 1)
        self.publisher_r2 = self.create_publisher(JointState, 'r2/joint_states', 1)

        # ROS publishets (estados)
        self.publisher_state_r1 = self.create_publisher(UInt8, 'ra1/motion_state', 1)
        self.publisher_state_r2 = self.create_publisher(UInt8, 'ra2/motion_state', 1)

        # ROS subscribers (metas)
        self.create_subscription(Float32MultiArray, 'ra1/joint_goals_q', self.listener_ros_ra1, 10)
        self.create_subscription(Float32MultiArray, 'ra2/joint_goals_q', self.listener_ros_ra2, 10)

        # ROS subscribers (metas)
        self.create_subscription(UInt8, 'ra1/effector_cmd', self.listener_efector_ra1, 1)
        self.create_subscription(UInt8, 'ra2/effector_cmd', self.listener_efector_ra2, 1)

        # Watchdog - Verificacion de conexiones esp32
        self.active_ra1 = False
        self.active_ra2 = False
        self.last_mqtt_time_ra1 = self.get_clock().now()
        self.last_mqtt_time_ra2 = self.get_clock().now()
        self.timer_watchdog_ra1 = self.create_timer(0.5, self.check_timeout_ra1)
        self.timer_watchdog_ra2 = self.create_timer(0.5, self.check_timeout_ra2)

        # MQTT topics
        self.topic_sub_r1     = "ra_1/sensores" # datos de juntas, sensores y estados
        self.topic_juntas_r1  = "ra_1/juntas"   # publicador
        self.topic_efector_r1 = "ra_1/efector"   # publicador

        self.topic_sub_r2     = "ra_2/sensores" # datos de juntas, sensores y estados
        self.topic_juntas_r2  = "ra_2/juntas"   # publicador
        self.topic_efector_r2 = "ra_2/efector"   # publicador

        # Paso (grados) para cuantizar comandos (según hardware)
        self.paso_q1 = 0.01929  # aproximación para PG47 + 400 pulse/rev
        self.paso_q2 = 0.9      # si tus NEMA17 están a 0.9°/paso (half-step)
        self.paso_q3 = 0.9

        # MQTT client
        self.mqtt_client = mqtt.Client()
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_message = self.on_message
        self.mqtt_client.connect("192.168.100.208", 1883, 60)
        self.mqtt_client.loop_start()

    # ---------- ROS -> MQTT (metas) ----------
    def listener_ros_ra1(self, msg: Float32MultiArray):
        if len(msg.data) < 3:
            self.get_logger().warn("ra1/joint_goals_q debe tener 3 valores.")
            return

        # Conversion a grados
        q1_deg = math.degrees(msg.data[0])
        q2_deg = math.degrees(msg.data[1])

        # Relacion de movimiento engranaje-cremallera
        angulo_q3_deg = math.degrees(msg.data[2] / 0.0225)

        payload = {
            "q1": self.mover_a_angulo(q1_deg, paso=self.paso_q1),
            "q2": self.mover_a_angulo(q2_deg, paso=self.paso_q2),
            "q3": self.mover_a_angulo(angulo_q3_deg, paso=self.paso_q3)
        }
        self.mqtt_client.publish(self.topic_juntas_r1, json.dumps(payload))
        self.get_logger().info("Meta enviada a ra1 (MQTT).")

    def listener_ros_ra2(self, msg: Float32MultiArray):
        if len(msg.data) < 3:
            self.get_logger().warn("ra2/joint_goals_q debe tener 3 valores.")
            return

        q1_deg = math.degrees(msg.data[0])
        q2_deg = math.degrees(msg.data[1])
        angulo_q3_deg = math.degrees(msg.data[2] / 0.0225)

        payload = {
            "q1": self.mover_a_angulo(q1_deg, paso=self.paso_q1),
            "q2": self.mover_a_angulo(q2_deg, paso=self.paso_q2),
            "q3": self.mover_a_angulo(angulo_q3_deg, paso=self.paso_q3)
        }
        self.mqtt_client.publish(self.topic_juntas_r2, json.dumps(payload))
        self.get_logger().info("Meta enviada a ra2 (MQTT).")
    

    def listener_efector_ra1(self, msg: UInt8):
        efector = msg.data
        payload = {
            "efector": efector
        }
        self.mqtt_client.publish(self.topic_efector_r1, json.dumps(payload))
        self.get_logger().info("Meta enviada a ra1 efector  (MQTT).")
    
    def listener_efector_ra2(self, msg: UInt8):
        efector = msg.data
        payload = {
            "efector": efector
        }
        self.mqtt_client.publish(self.topic_efector_r2, json.dumps(payload))
        self.get_logger().info("Meta enviada a ra2 efector  (MQTT).")

    def mover_a_angulo(self, angulo_objetivo: float, paso: float) -> float:
        """
        Cuantiza el ángulo objetivo al múltiplo de 'paso' más cercano.
        Devuelve el ángulo cuantizado en grados.
        """
        desplazamiento_valido = round(angulo_objetivo / paso) * paso
        return round(desplazamiento_valido, 4)

    # ---------- MQTT -> ROS (feedback) ----------
    def on_connect(self, client, userdata, flags, rc):
        if rc == 0:
            self.get_logger().info("Conectado al broker MQTT.")
            client.subscribe(self.topic_sub_r1)
            client.subscribe(self.topic_sub_r2)
        else:
            self.get_logger().error(f"Error de conexión MQTT: rc={rc}")

    def on_message(self, client, userdata, msg):
        try:
            data = json.loads(msg.payload.decode("utf-8"))

            # Esperado desde ESP32: q1_mov,q2_mov,q3_mov en GRADOS
            q1 = float(data.get("q1_mov", 0.0))
            q2 = float(data.get("q2_mov", 0.0))
            q3 = float(data.get("q3_mov", 0.0))

            js = JointState()
            js.header.stamp = self.get_clock().now().to_msg()

            if msg.topic == self.topic_sub_r1:
                self.active_ra1 = True
                self.last_mqtt_time_ra1 = self.get_clock().now()

                js.name = ['r1_brazo_joint', 'r1_antebrazo_joint', 'r1_efector_joint']
                js.position = [math.radians(q1), math.radians(q2), math.radians(q3)*0.0225]
                self.publisher_r1.publish(js)

                estado_r1 = UInt8()
                estado_r1.data = int(data.get("estado", 0))
                self.publisher_state_r1.publish(estado_r1)

                self.get_logger().warn(f'[{estado_r1}] estado de movimiento r1')

            elif msg.topic == self.topic_sub_r2:
                self.active_ra2 = True
                self.last_mqtt_time_ra2 = self.get_clock().now()

                js.name = ['r2_brazo_joint', 'r2_antebrazo_joint', 'r2_efector_joint']
                js.position = [math.radians(q1), math.radians(q2), math.radians(q3)*0.0225]
                self.publisher_r2.publish(js)

                estado_r2 = UInt8()
                estado_r2.data = int(data.get("estado", 0))
                self.publisher_state_r2.publish(estado_r2)

                self.get_logger().warn(f'[{estado_r2}] estado de movimiento r2')


        except Exception as e:
            self.get_logger().error(f"Error procesando MQTT: {e}")

    # ---------- Watchdogs ----------
    def check_timeout_ra1(self):
        now = self.get_clock().now()
        if self.active_ra1 and (now - self.last_mqtt_time_ra1 > Duration(seconds=15.0)):
            self.get_logger().warn("RA1: no llegan datos MQTT, se detiene publicación.")
            self.active_ra1 = False

    def check_timeout_ra2(self):
        now = self.get_clock().now()
        if self.active_ra2 and (now - self.last_mqtt_time_ra2 > Duration(seconds=2.0)):
            self.get_logger().warn("RA2: no llegan datos MQTT, se detiene publicación.")
            self.active_ra2 = False


def main(args=None):
    rclpy.init(args=args)
    node = MQTTBridge()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
