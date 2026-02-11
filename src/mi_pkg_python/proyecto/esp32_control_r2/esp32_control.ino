#include <PubSubClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <AccelStepper.h>

// Pines motores paso a paso
#define STEP2 18
#define DIR2  19
#define STEP3 22
#define DIR3  23

// Pines Driver
static const int PIN_STEP = 25;  // -> PUL+
static const int PIN_DIR  = 27;  // -> DIR+

// --------------------
// Config según tu DIP: 400 pulse/rev (del motor)
// Reductora: PG47  46.656:1
// --------------------

static const long PULSES_PER_REV_MOTOR = 400;
static const float GEAR_RATIO = 46.656f;

static const long PULSES_PER_REV_OUT = (long)(PULSES_PER_REV_MOTOR * GEAR_RATIO);

// Convierte grados del eje de salida a pulsos
long outDegreesToPulses(float deg_out) {
float pulses = (deg_out / 360.0f) * (float)PULSES_PER_REV_OUT;
return lroundf(pulses);
}

AccelStepper motor1(AccelStepper::DRIVER, PIN_STEP, PIN_DIR);
AccelStepper motor2(AccelStepper::DRIVER, STEP2, DIR2);  // Q1
AccelStepper motor3(AccelStepper::DRIVER, STEP3, DIR3);  // Q2


float gradosPorPaso = 0.9;

// Variable de Control Stepper
int activar  = 0;
int estado   = 0;
int ultra    = 0;
float q1_mov = 0.0;
float q2_mov = 0.0;
float q3_mov = 0.0;

// Variables de control envio de mensajes
bool moving = false;
bool sent_final = false;
volatile bool nuevoTarget = false;
long target1;
int  target2, target3;

// GPIO de salidad Digital
int pin_led   = 2;

//  Credenciales Wifi
const char* ssid = "CARMEN GONZALEZ_";
const char* password = "123wa321vg";

// Credenciales MQTT
const char* mqtt_broker = "192.168.100.208";
const int mqtt_port     = 1883;
const char* cliente     = "ra_2_esp32";

// Temas MQTT Publicar
const char* tema_sub     = "ra_2/juntas";
const char* tema_pub_est = "ra_2/estados";
const char* tema_pub_sen = "ra_2/sensores";

// Variables de control de tiempo
unsigned long lastTime = 0;

// Creacion del objeto cliente
WiFiClient espClient;
PubSubClient client(espClient);

// Tamaño de mensaje JSON
const size_t capacidad_json = JSON_OBJECT_SIZE(30);


void setup() {
// Setup Serial
Serial.begin(115200);
// Setup Wifi
setup_wifi();
// Setup MQTT
conexion();
// Manejo del rele
pinMode(pin_led, OUTPUT);

// NEMA 23
// AccelStepper
motor1.setMaxSpeed(4665.6);       // pulsos/seg (ojo: a mayor, más exigente)
motor1.setAcceleration(3110);   // pulsos/seg^2
motor1.setMinPulseWidth(5);     // us (seguro para DM542T)

// NEMA 17
motor2.setMaxSpeed(99.9);
motor2.setAcceleration(66.7);
motor2.setPinsInverted(true, false, false); //

motor3.setMaxSpeed(200);
motor3.setAcceleration(100);

// Referencia inicial (si estás arrancando desde "cero")
motor1.setCurrentPosition(0);
motor2.setCurrentPosition(0);
motor3.setCurrentPosition(0);
}

void loop() {
Loop_MQTT();
if (nuevoTarget) {
   nuevoTarget = false;

   motor1.moveTo(target1);
   motor2.moveTo(target2);
   motor3.moveTo(target3);

   moving = true;
   sent_final = false;
}

motor1.run();
motor2.run();
motor3.run();

// actualizacion de grados
q1_mov = (motor1.currentPosition() * 360.0f) / (float)PULSES_PER_REV_OUT;
q2_mov = motor2.currentPosition() * gradosPorPaso;
q3_mov = motor3.currentPosition() * gradosPorPaso;

// Detectar si ya terminó el movimiento
bool stillMoving = anyMotorMoving();

if (moving && !stillMoving && !sent_final) {
  // acaba de terminar
  // Enviar un último paquete final
  envioDatos(tema_pub_sen, estado, ultra, q1_mov, q2_mov, q3_mov);
  sent_final = true;
  moving = false;
}

// Publicación periódica cada 100 ms SOLO si está moviendo
if (moving && (millis() - lastTime >= 100)) {
  estado = 1;
  ultra = ultra + 1;
  envioDatos(tema_pub_sen, estado, ultra, q1_mov, q2_mov, q3_mov);
  lastTime = millis();
}

if (activar == 1){
   digitalWrite(pin_led, HIGH);  // Enciende el LED

   }
else {
   digitalWrite(pin_led, LOW);  // Enciende el LED
}

}
