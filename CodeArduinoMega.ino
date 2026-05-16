#include <Servo.h>

// ================= PINES Y HARDWARE =================

// --- ROBOT 1 ---
#define R1_NEMA23_STEP 24  
#define R1_NEMA23_DIR  26
#define R1_NEMA17_STEP 2   
#define R1_NEMA17_DIR  5      
#define R1_SERVO1_PIN  44
#define R1_SERVO2_PIN  46                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
#define R1_ON_PIN      15  

// --- ROBOT 2 ---
#define R2_NEMA23_STEP 28  
#define R2_NEMA23_DIR  30
#define R2_NEMA17_STEP 3   
#define R2_NEMA17_DIR  6
#define R2_SERVO1_PIN  45
#define R2_SERVO2_PIN  7
#define R2_ON_PIN      16  

#define ENABLE_PIN     8   

// ================= CONFIGURACIÓN MOTORES ============
const int stepsPerRev = 200;

// --- Configuración NEMA 23 ---
const int   micro_N23 = 16;
const float gear_N23  = 1.0;
const long  int_N23   = 3000; 

// --- Configuración NEMA 17 ---
const int   micro_N17 = 1;
const float gear_N17  = 3.0;  
const long  int_N17   = 7000; 

const float stepsDeg_N23 = (stepsPerRev * micro_N23 * gear_N23) / 360.0;
const float stepsDeg_N17 = (stepsPerRev * micro_N17 * gear_N17) / 360.0;

// ================= OBJETOS Y VARIABLES ==============
Servo servo11, servo12, servo21, servo22;
float data[10]; 

// ================= FUNCIONES ========================

void move4Steppers(float q11, float q12, float q21, float q22) {
  long s11 = abs(q11 * stepsDeg_N23);
  long s12 = abs(q12 * stepsDeg_N17);
  long s21 = abs(q21 * stepsDeg_N23);
  long s22 = abs(q22 * stepsDeg_N17);

  digitalWrite(R1_NEMA23_DIR, (q11 >= 0));
  digitalWrite(R1_NEMA17_DIR, (q12 >= 0));
  digitalWrite(R2_NEMA23_DIR, (q21 >= 0));
  digitalWrite(R2_NEMA17_DIR, (q22 >= 0));
  
  delayMicroseconds(5); 

  unsigned long t11 = 0, t12 = 0, t21 = 0, t22 = 0;
  
  while (s11 > 0 || s12 > 0 || s21 > 0 || s22 > 0) {
    unsigned long now = micros();

    if (s11 > 0 && (now - t11 >= int_N23)) {
      digitalWrite(R1_NEMA23_STEP, HIGH); delayMicroseconds(2); digitalWrite(R1_NEMA23_STEP, LOW);
      t11 = now; s11--;
    }
    if (s12 > 0 && (now - t12 >= int_N17)) {
      digitalWrite(R1_NEMA17_STEP, HIGH); delayMicroseconds(2); digitalWrite(R1_NEMA17_STEP, LOW);
      t12 = now; s12--;
    }
    if (s21 > 0 && (now - t21 >= int_N23)) {
      digitalWrite(R2_NEMA23_STEP, HIGH); delayMicroseconds(2); digitalWrite(R2_NEMA23_STEP, LOW);
      t21 = now; s21--;
    }
    if (s22 > 0 && (now - t22 >= int_N17)) {
      digitalWrite(R2_NEMA17_STEP, HIGH); delayMicroseconds(2); digitalWrite(R2_NEMA17_STEP, LOW);
      t22 = now; s22--;
    }
  }
}

bool readSerialData() {
  if (!Serial.available()) return false;
  String line = Serial.readStringUntil('\n');
  line.trim();
  int index = 0;
  char buffer[line.length() + 1];
  line.toCharArray(buffer, sizeof(buffer));
  char* token = strtok(buffer, ",");
  while (token != NULL && index < 10) {
    data[index] = atof(token);
    token = strtok(NULL, ",");
    index++;
  }
  return (index == 10);
}

// ================= SETUP ============================
void setup() {
  Serial.begin(9600);

  pinMode(R1_NEMA23_STEP, OUTPUT); pinMode(R1_NEMA23_DIR, OUTPUT);
  pinMode(R1_NEMA17_STEP, OUTPUT); pinMode(R1_NEMA17_DIR, OUTPUT);
  pinMode(R2_NEMA23_STEP, OUTPUT); pinMode(R2_NEMA23_DIR, OUTPUT);
  pinMode(R2_NEMA17_STEP, OUTPUT); pinMode(R2_NEMA17_DIR, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(R1_ON_PIN, OUTPUT);
  pinMode(R2_ON_PIN, OUTPUT);

  digitalWrite(ENABLE_PIN, LOW); 

  servo11.attach(R1_SERVO1_PIN); servo12.attach(R1_SERVO2_PIN);
  servo21.attach(R2_SERVO1_PIN); servo22.attach(R2_SERVO2_PIN);

  // Inicializar en 90
  servo11.write(90); servo12.write(90);
  servo21.write(90); servo22.write(90);

  Serial.println("SISTEMA LISTO.");
  Serial.println("Asegurate de tener 'Nueva Linea' activado en el monitor serie.");
}

// ================= LOOP =============================
void loop() {
  if (readSerialData()) {
    float r1_n23 = data[0]; 
    float r1_n17 = data[1]; 
    float r1_sv1 = data[2]; 
    float r1_sv2 = data[3]; 
    int   r1_on  = (int)data[4]; 

    float r2_n23 = data[5]; 
    float r2_n17 = data[6]; 
    float r2_sv1 = data[7]; 
    float r2_sv2 = data[8]; 
    int   r2_on  = (int)data[9]; 

    // DEBUG: Ver que valores llegaron
    Serial.print("Recibido: R2-Steppers -> N23:");
    Serial.print(r2_n23);
    Serial.print(" N17:");
    Serial.println(r2_n17);

    servo11.write(r1_sv1); servo12.write(r1_sv2);
    servo21.write(r2_sv1); servo22.write(r2_sv2);

    digitalWrite(R1_ON_PIN, r1_on ? HIGH : LOW);
    digitalWrite(R2_ON_PIN, r2_on ? HIGH : LOW);

    // LLAMADA CORREGIDA AQUI:
    move4Steppers(r1_n23, r1_n17, r2_n23, r2_n17);
    
    Serial.println("Movimiento terminado.");
  }
}