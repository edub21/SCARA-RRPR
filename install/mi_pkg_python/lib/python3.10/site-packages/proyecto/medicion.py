import cv2
import yaml
import numpy as np
from pupil_apriltags import Detector

# 1. Cargar parámetros de calibración desde el YAML
with open("/home/edub/ros2_ws/src/mi_pkg_python/proyecto/camera_calibration.yaml", 'r') as f:
    calib_data = yaml.safe_load(f)

# Extraer matrices (ajusta las llaves 'camera_matrix' y 'distortion_coefficients' según tu YAML)
K = np.array(calib_data['camera_matrix'])
D = np.array(calib_data['distortion_coefficients'])

# 2. Configurar detector y cámara
at_detector = Detector(families='tag36h11')
cap = cv2.VideoCapture(0)

# Obtener dimensiones para la rectificación
ret, frame = cap.read()
h, w = frame.shape[:2]

# Pre-calcular los mapas de rectificación para ahorrar procesamiento en el loop
# Esto elimina la distorsión de "barril" del ojo de pez
new_K, _ = cv2.getOptimalNewCameraMatrix(K, D, (w, h), 1, (w, h))
map1, map2 = cv2.initUndistortRectifyMap(K, D, None, new_K, (w, h), cv2.CV_16SC2)

print("Buscando AprilTag ID 1 con corrección de imagen...")

while True:
    ret, frame = cap.read()
    if not ret: break

    # 3. APLICAR CORRECCIÓN OJO DE PEZ
    # Remapeamos los píxeles para "estirar" la imagen y que las líneas sean rectas
    frame_undistorted = cv2.remap(frame, map1, map2, interpolation=cv2.INTER_LINEAR)

    # Detección sobre la imagen corregida
    gray = cv2.cvtColor(frame_undistorted, cv2.COLOR_BGR2GRAY)
    tags = at_detector.detect(gray)

    for tag in tags:
        if tag.tag_id == 1:
            # Imprimir datos corregidos
            print(f"ID 1 detectado en Centro: {tag.center}")
            
            # Dibujar visualización
            for i in range(4):
                p1 = tuple(tag.corners[i].astype(int))
                p2 = tuple(tag.corners[(i + 1) % 4].astype(int))
                cv2.line(frame_undistorted, p1, p2, (0, 255, 0), 2)
            cv2.putText(frame_undistorted, "TAG 1", tuple(tag.center.astype(int)), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

    cv2.imshow("Imagen Corregida (Undistorted)", frame_undistorted)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()