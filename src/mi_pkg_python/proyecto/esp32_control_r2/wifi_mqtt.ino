void setup_wifi() {
// Conexión Wifi
delay(10);
Serial.println();
Serial.print("Conectando a ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
}
Serial.println("");
Serial.print("WiFi conectado - Dirección IP del ESP: ");
Serial.println(WiFi.localIP());
}

void reconnect() {
// Control de conexión MQTT
while (!client.connected()) {
   Serial.print("Intentando conexión MQTT...");
   if (client.connect(cliente)) {
      Serial.println("Conectado");
      // Suscripción a TEMAS
      client.subscribe(tema_sub, 1);
   } else {
      Serial.print("Falló, rc=");
      Serial.print(client.state());
      Serial.println("Intentando de nuevo en 2 segundos");
      delay(2000);
   }
}
}

void conexion() {
// Conexión MQTT
client.setServer(mqtt_broker, mqtt_port);
client.setCallback(callback);
}

void Loop_MQTT() {
// Manejo MQTT
if (!client.connected()) {
   reconnect();
}
client.loop();
}

void envioDatos(const char* mqtt_topic_publicar, int estado, int ultra, float q1, float q2, float q3) {
DynamicJsonDocument mensaje(256);

if (mqtt_topic_publicar == tema_pub_est) {
   mensaje["estado"]   = estado;
   String mensaje_json;
   serializeJson(mensaje, mensaje_json);
   client.publish(mqtt_topic_publicar, mensaje_json.c_str(), false);
}

if (mqtt_topic_publicar == tema_pub_sen) {
   mensaje["ultra"]   = ultra;
   mensaje["q1_mov"]  = q1;
   mensaje["q2_mov"]  = q2;
   mensaje["q3_mov"]  = q3;
   String mensaje_json;
   serializeJson(mensaje, mensaje_json);
   client.publish(mqtt_topic_publicar, mensaje_json.c_str(), false);
}


}

void callback(char* topic, byte* payload, unsigned int length) {
StaticJsonDocument<capacidad_json> doc;
char buffer[length + 1];
memcpy(buffer, payload, length);
buffer[length] = '\0';  // Asegura que el buffer tenga fin de cadena

DeserializationError error = deserializeJson(doc, buffer);

if (error) {
   Serial.print("Error al deserializar JSON: ");
   Serial.println(error.c_str());
   return;
}

String topico(topic);
if (topico == "ra/juntas") {
   if (doc.containsKey("q1") && doc.containsKey("q2") && doc.containsKey("q3")) {
      float q1 = doc["q1"]; // NEMA 23
      float q2 = doc["q2"]; // NEMA 17
      float q3 = doc["q3"]; // NEMA 17

      long pasos1 = outDegreesToPulses(q1);
      int pasos2 = round(q2 / gradosPorPaso);
      int pasos3 = round(q3 / gradosPorPaso);

      Serial.print("Recibido q1: ");
      Serial.print(q1);
      Serial.print(" → pasos: ");
      Serial.print(pasos1);


      Serial.print("Recibido q2: ");
      Serial.print(q2);
      Serial.print(" → pasos: ");
      Serial.print(pasos2);

      Serial.print(" Recibido q3: ");
      Serial.print(q3);
      Serial.print(" → pasos: ");
      Serial.println(pasos3);

      target1 = pasos1;
      target2 = pasos2;
      target3 = pasos3;

      nuevoTarget = true;   // <-- SOLO esto

   }

   if (doc.containsKey("avanzar")) {
      activar = doc["avanzar"];
   }
}
}