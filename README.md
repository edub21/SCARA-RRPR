# SCARA Robot Control System: ROS 2 + Arduino Mega 🤖

[![ROS 2](https://img.shields.io/badge/ROS%202-Humble-blue)](https://docs.ros.org/en/humble/index.html)
[![Python](https://img.shields.io/badge/Python-3.10-yellow)](https://www.python.org/)
[![Arduino](https://img.shields.io/badge/Arduino-Mega%202560-00979D)](https://www.arduino.cc/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

Este proyecto implementa un ecosistema completo para el control de un brazo robótico **SCARA** (Selective Compliance Assembly Robot Arm). Integra percepción visual, planificación mediante una máquina de estados, control cinemático en ROS 2 y ejecución de bajo nivel en hardware real.

---

## 🏗️ ¿Qué es un Robot SCARA?
El robot SCARA destaca por su configuración de articulaciones **RRP** (Rotacional-Rotacional-Prismática), lo que le permite mantener una alta rigidez en el eje Z mientras se mueve con gran velocidad y precisión en el plano XY. 

### Cinemática del Proyecto
*   **Cinemática Directa:** Calculada mediante parámetros Denavit-Hartenberg (D-H) para mapear los ángulos de los motores a la posición del efector final.
*   **Cinemática Inversa:** Implementada para resolver las coordenadas cartesianas deseadas en ángulos de articulación, optimizando la trayectoria para evitar singularidades.

---

## 🛰️ Arquitectura del Systema
El sistema se divide en tres capas principales:

1.  **Capa de Percepción y Toma de Decisiones (ROS 2):**
    *   `fsm.py`: Máquina de Estados Finitos que coordina las tareas (Búsqueda, Captura, Movimiento, Depósito).
    *   `vision_to_rviz.py`: Procesa datos de AprilTags para geolocalizar objetos en el espacio 3D.
2.  **Capa de Control y Comunicación:**
    *   `driver_scara.py`: Nodo central que gestiona la teleoperación y los comandos de trayectoria.
    *   `puente_mqtt_ros2.py`: Interfaz de comunicación para monitoreo remoto.
3.  **Capa de Hardware (Arduino Mega):**
    *   `mega.py`: Nodo de comunicación serial.
    *   Firmware `.ino`: Control de motores a pasos (Steppers) con aceleración suave.

---

## 🕹️ ¡Pruébalo ahora! (Visualizador Interactivo)

¿No tienes ROS instalado? No hay problema. Haz clic en el siguiente enlace para ver el modelo 3D interactivo y mover las articulaciones directamente desde tu navegador:

[ > CLIC AQUÍ PARA ABRIR EL VISUALIZADOR 3D < ](https://edub21.github.io/SCARA-RRPR/)


---

## 🚀 Instalación y Ejecución

### Requisitos previos
*   ROS 2 (Humble recomendado)
*   Ubuntu 22.04 o similar
*   Librerías de Python: `opencv-python`, `pyserial`

### Configuración del Workspace
Asumiendo que has clonado este repositorio y la estructura `src` ya está presente:

```bash
# Navegar a la raíz del proyecto
cd SCARA

# Instalar dependencias de ROS
rosdep install -i --from-path src --rosdistro humble -y

# Compilar el proyecto
colcon build --symlink-install

# Cargar el entorno
source install/setup.bash
```

### Lanzamiento del Proyecto
Para visualizar el robot en Rviz2 y activar el driver:
```bash
ros2 launch mi_pkg_python todo_scara.launch.py
```

---

## 🛠️ Estructura del Repositorio
*   `src/mi_pkg_python/urdf/`: Modelos geométricos y mallas del robot.
*   `src/mi_pkg_python/proyecto/`: Nodos lógicos y scripts principales.
*   `src/mi_pkg_python/cam/`: Calibración y procesamiento de visión.
*   `src/avig_msg/`: Definiciones de mensajes y acciones personalizadas.
