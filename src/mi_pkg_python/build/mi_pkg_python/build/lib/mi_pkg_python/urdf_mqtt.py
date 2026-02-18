import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
from std_msgs.msg import Float32, Int32

from sensor_msgs.msg import JointState

import paho.mqtt.client as mqtt
import json

import math

class MQTTBridge(Node):
    def __init__(self):
        super().__init__('mqtt_bridge')

        # Angulos [rad]
        self.real_q1 = 0.0
        self.real_q2 = 0.0
        # distancia [m]
        self.real_q3 = 0.0

        self.pub = self.create_publisher( Float32, 'sensor_bateria', 1) # mqtt a ros

        # ros a mqtt
        self.subscription = self.create_subscription(
            JointState,
            '/joint_states',
            self.listener_ros, 1
            )

        self.last_data = None
        self.active = True  # control de publicación activa
        self.last_mqtt_time = self.get_clock().now()

        self.timer = self.create_timer(0.1, self.publish_sensor_data)       # Publicador (10 Hz)
        self.timer_watchdog = self.create_timer(0.5, self.check_timeout)    # Verificador de tiempo

        self.topic_sub = "ra/sensores"
        self.topic_pub = "ra/juntas"
        self.mqtt_client = mqtt.Client()
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_message = self.on_message
        self.mqtt_client.connect("192.168.100.208", 1883, 60)
        self.mqtt_client.loop_start()

    def listener_ros(self, msg):
        q1_mov = 0.0
        q2_mov = 0.0
        q3_mov = 0.0
        for i, name in enumerate(msg.name):
            # Resolucion del stepper 0.9
            if name == "brazo_joint":
                # nema 23 PG47
                meta = round(math.degrees(msg.position[i]),4)
                self.real_q1, q1_mov = self.mover_a_angulo_discreto(meta,self.real_q1, paso=0.019)
            if name == "antebrazo_joint":
                # nema 17
                meta = round(math.degrees(msg.position[i]),4)
                self.real_q2, q2_mov = self.mover_a_angulo_discreto(meta,self.real_q2)
            if name == "efector_joint":
                # nema 17
                # relacion geometrica lineal / angular 
                angulo = math.degrees(msg.position[i]/0.0225)
                meta = round(angulo,4)
                self.real_q3, q3_mov = self.mover_a_angulo_discreto(meta,self.real_q3)

        payload = {
                    "q1": q1_mov,
                    "q2": q2_mov,
                    "q3": q3_mov
                  }
        msg_mqtt = json.dumps(payload)
        self.mqtt_client.publish(self.topic_pub, msg_mqtt)
        print("Mensaje Enviado")

    def mover_a_angulo_discreto(self, angulo_objetivo, angulo_actual, paso=0.9):
        """
        Calcula el desplazamiento al múltiplo de 'paso' más cercano al ángulo objetivo.
        Retorna:
            - el nuevo ángulo corregido (múltiplo de paso)
            - el desplazamiento angular necesario desde el ángulo actual
        """

        # Calcula desplazamiento
        desplazamiento = angulo_objetivo - angulo_actual

        # Redondea el ángulo objetivo al múltiplo más cercano
        desplazamiento_valido = round(desplazamiento / paso) * paso

        meta_ajustada = angulo_actual + desplazamiento_valido
        print(f"[INFO] Objetivo :{angulo_objetivo}°")
        print(f"[INFO] Objetivo ajustado: {meta_ajustada}° (múltiplo de {paso}°)")
        print(f"[INFO] Desplazamiento desde actual: {desplazamiento_valido:.2f}°")

        return round(meta_ajustada,2), round(desplazamiento_valido,2)


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
                self.last_data = float(data["ultra"])
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