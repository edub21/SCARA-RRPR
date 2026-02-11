import paho.mqtt.client as mqtt
import json
import time

# Configuración del broker
BROKER            = "192.168.100.208" #Ip del computador o Localhost
TOPIC_PUB_SEN     = "rm1/sensores"
TOPIC_PUB_EST     = "rm1/estados"
TOPIC_SUB         = "rm1/acciones"
CLIENT_ID         = "cliente_Equipo2"

# Callback cuando se conecta al broker
def on_connect(client, userdata, flags, rc, properties=None):
   if rc == 0:
      print("Conectado al broker MQTT")
      client.subscribe(TOPIC_SUB)

   else:
      print(f"Error de conexión: código {rc}")

# Callback al recibir un mensaje
def on_message(client, userdata, msg):
   try:
      mensaje = msg.payload.decode("utf-8")
      data = json.loads(mensaje)
      if msg.topic == TOPIC_SUB:
            print("Mensaje recido del Equipo1:", data["vel"]["u_meta"])

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
            "EncoderI": 20,
            "EncoderD": 30,
            }
      mensaje = json.dumps(payload)
      client.publish(TOPIC_PUB_SEN, mensaje)
      print("Publicado:", payload)

      payload2 = {
            "Estado": "Encedido"
            }
      mensaje2 = json.dumps(payload2)
      client.publish(TOPIC_PUB_EST, mensaje2)
      #print("Publicado:", payload)
      time.sleep(1)

except KeyboardInterrupt:
   print("\n Finalizando conexión MQTT...")

finally:
   client.loop_stop()
   client.disconnect()
   print(" Desconectado correctamente.")