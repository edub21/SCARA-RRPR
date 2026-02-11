import paho.mqtt.client as mqtt
import json
import time

# Configuración del broker
BROKER            = "192.168.100.208" # Ip del computador o localhost
TOPIC_SUB_SEN     = "ra/sensores"
TOPIC_SUB_EST     = "ra/estados"
TOPIC_PUB         = "ra/juntas"
CLIENT_ID         = "cliente_rm1"

# Callback cuando se conecta al broker
def on_connect(client, userdata, flags, rc, properties=None):
   if rc == 0:
      print("Conectado al broker MQTT")
      client.subscribe(TOPIC_SUB_SEN)
      client.subscribe(TOPIC_SUB_EST)

   else:
      print(f"Error de conexión: código {rc}")

# Callback al recibir un mensaje
def on_message(client, userdata, msg):
   try:
      mensaje = msg.payload.decode("utf-8")
      data = json.loads(mensaje)
      if msg.topic == TOPIC_SUB_SEN:
            print("Mensaje recido del Equipo2 Ultrasónico:", data["q1_mov"], data["q2_mov"], data["q3_mov"])

      if msg.topic == TOPIC_SUB_EST:
            print("Mensaje recido del Equipo2 Estado:", data["estado"])

   except Exception as e:
      print("Error procesando mensaje:", e)

client = mqtt.Client(client_id=CLIENT_ID, protocol=mqtt.MQTTv311)

# Asociar funciones de callback
client.on_connect = on_connect
client.on_message = on_message

# Conexión al broker
client.connect(BROKER)

# Iniciar loop en segundo plano
client.loop_start()

# Envío continuo de mensajes cada segundo
try:
   while True:
      payload = {
            "q1": 35,
            "q2": 120,
            "q3": 30,
            "avanzar": 1
            }
      mensaje = json.dumps(payload)
      client.publish(TOPIC_PUB, mensaje)
      #print("Publicado en datos_1:", payload)
      time.sleep(30)

except KeyboardInterrupt:
   print("\n Finalizando conexión MQTT...")

finally:
   client.loop_stop()
   client.disconnect()
   print(" Desconectado correctamente.")