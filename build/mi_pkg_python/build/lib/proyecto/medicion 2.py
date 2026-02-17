import cv2
import yaml
import numpy as np
from pupil_apriltags import Detector

# 1. Cargar parámetros de calibración
with open("/home/edub/ros2_ws/src/mi_pkg_python/proyecto/camera_calibrationJason.yaml", 'r') as f:
    calib_data = yaml.safe_load(f)

# CORRECCIÓN: Acceder a ['data'] y reestructurar la matriz
# Para K (Camera Matrix) que es 3x3
raw_K = calib_data['camera_matrix']['data']
K = np.array(raw_K, dtype=np.float64).reshape((3, 3))

# Para D (Distortion Coefficients) que suele ser 1x5 o 1x8
raw_D = calib_data['distortion_coefficients']['data']
D = np.array(raw_D, dtype=np.float64)

print("Matrices cargadas correctamente:")
print(f"K:\n{K}")
print(f"D: {D}")

# 2. Configurar detector y cámara
at_detector = Detector(families='tag36h11')
cap = cv2.VideoCapture(0) 
cap.set(cv2.CAP_PROP_AUTOFOCUS, 0)
cap.set(cv2.CAP_PROP_FOCUS, 25)
cap.set(cv2.CAP_PROP_ZOOM, 0)

# Obtener dimensiones iniciales
ret, frame = cap.read()
if not ret:
    print("No se pudo acceder a la cámara")
    exit()
h, w = frame.shape[:2]

# Pre-calcular mapas de rectificación
# El parámetro '1' en getOptimalNewCameraMatrix mantiene todos los píxeles (puede dejar bordes negros)
new_K, roi = cv2.getOptimalNewCameraMatrix(K, D, (w, h), 1, (w, h))
map1, map2 = cv2.initUndistortRectifyMap(K, D, None, new_K, (w, h), cv2.CV_16SC2)

print("Buscando AprilTags ID 1 y 2...")

while True:
    ret, frame = cap.read()
    if not ret: break

    # Aplicar corrección de lente (Undistort)
    frame_undistorted = cv2.remap(frame, map1, map2, interpolation=cv2.INTER_LINEAR)

    # Detección
    gray = cv2.cvtColor(frame_undistorted, cv2.COLOR_BGR2GRAY)
    tags = at_detector.detect(gray)

    for tag in tags:
        # Filtrar solo por ID 1 y ID 2
        if tag.tag_id in [1, 2]:
            print(f"--- Tag Detectado: ID {tag.tag_id} ---")
            print(f"Centro: {tag.center}")
            print(f"Esquinas: {tag.corners}")
            print(f"Error de decisión: {tag.decision_margin}")
            
            # Dibujar en pantalla
            pts = tag.corners.reshape((-1, 1, 2)).astype(np.int32)
            cv2.polylines(frame_undistorted, [pts], True, (0, 255, 0), 2)
            cv2.putText(frame_undistorted, f"ID: {tag.tag_id}", tuple(tag.center.astype(int)), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 0, 255), 2)

    cv2.imshow("Vision Corregida - Medicion", frame_undistorted)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()