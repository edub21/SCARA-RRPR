
import cv2
import numpy as np
import yaml
import time
import sys
from scipy.spatial.transform import Rotation as R

# --- Cargar parámetros de calibración desde YAML ---
with open("camera_calibration.yaml", 'r') as f:
    calib_data = yaml.safe_load(f)

K = np.array(calib_data['camera_matrix']['data']).reshape(3, 3)
dist = np.array(calib_data['distortion_coefficients']['data'])

# --- Inicializar detección de AprilTags ---
from pupil_apriltags import Detector
at_detector = Detector(families='tag36h11')

# --- Parámetros del tag ---
tag_size = 0.04  # Tamaño del tag en metros (100 mm)

# --- Captura desde la cámara (DroidCam IP) ---
# Use la URL de DroidCam proporcionada
stream_url = "http://10.40.21.248:4747/video"
cap = cv2.VideoCapture(stream_url)
if not cap.isOpened():
    # Intentar corregir casos donde la IP y el puerto estén concatenados como
    # 10.40.248.4747 (5 segmentos) -> transformar a 10.40.248.47:4747
    try:
        host = stream_url.split('//', 1)[1].split('/', 1)[0]
        parts = host.split('.')
        if len(parts) == 5:
            ip = '.'.join(parts[:4])
            port = parts[4]
            corrected = f"http://{ip}:{port}/video"
            print(f"Intentando URL corregida: {corrected}")
            cap.open(corrected)
            if cap.isOpened():
                stream_url = corrected
    except Exception:
        pass

if not cap.isOpened():
    print(f"No se pudo abrir la cámara en {stream_url}")
    sys.exit(1)

# Intento de forzar la máxima resolución disponible en la cámara
preferred_resolutions = [
    (1920, 1080),
    (1280, 720),
    (960, 540),
    (640, 480)
]

resolution_set = False
for rw, rh in preferred_resolutions:
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, rw)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, rh)
    # pequeña pausa para aplicar los cambios en la cámara
    time.sleep(0.2)
    actual_w = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    actual_h = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    if actual_w == rw and actual_h == rh:
        print(f"Resolución establecida: {actual_w}x{actual_h}")
        resolution_set = True
        break

if not resolution_set:
    actual_w = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    actual_h = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    print(f"No se pudo forzar una resolución preferida. Resolución actual: {actual_w}x{actual_h}")

cv2.namedWindow("AprilTag Detection", cv2.WINDOW_NORMAL)
cv2.resizeWindow("AprilTag Detection", 800, 600)

last_print_time = time.time()

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Corregir distorsión
    h, w = frame.shape[:2]
    newcameramtx, _ = cv2.getOptimalNewCameraMatrix(K, dist, (w, h), 1, (w, h))
    undistorted = cv2.undistort(frame, K, dist, None, newcameramtx)

    # Convertir a escala de grises
    gray = cv2.cvtColor(undistorted, cv2.COLOR_BGR2GRAY)

    # Detección
    tags = at_detector.detect(
        gray,
        estimate_tag_pose=True,
        camera_params=(K[0, 0], K[1, 1], K[0, 2], K[1, 2]),
        tag_size=tag_size
    )

    tag_poses = {}
    tag_centers = {}
    tag_by_id = {}

    for tag in tags:
        id = tag.tag_id
        corners = np.int32(tag.corners)
        center = np.mean(corners, axis=0).astype(int)

        cv2.polylines(undistorted, [corners], True, (0, 255, 0), 2)
        cv2.putText(undistorted, f"ID: {id}", tuple(center), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 0, 0), 2)

        t = tag.pose_t.flatten() * 1000  # Convertir a mm
        tag_poses[id] = t
        tag_centers[id] = tuple(center)
        tag_by_id[id] = tag

    if 0 in tag_by_id:
        # Obtener transformación del tag 0
        ref_tag = tag_by_id[0]
        R0 = ref_tag.pose_R
        t0 = ref_tag.pose_t.reshape(3, 1)
        T0 = np.hstack([R0, t0])
        T0 = np.vstack([T0, [0, 0, 0, 1]])
        T0_inv = np.linalg.inv(T0)

        # Mostrar orientación del tag 0 (ángulos Euler)
        r_obj = R.from_matrix(R0)
        euler = r_obj.as_euler('xyz', degrees=True)
        print(f"Orientación Tag 0 (Euler): Roll={euler[0]:.1f}°, Pitch={euler[1]:.1f}°, Yaw={euler[2]:.1f}°")

        # Calcular transformaciones relativas corregidas
        print("\nPosiciones relativas (corregidas) en mm respecto al tag 0:")
        for id, tag in tag_by_id.items():
            if id == 0:
                continue

            R_tag = tag.pose_R
            t_tag = tag.pose_t.reshape(3, 1)
            T = np.hstack([R_tag, t_tag])
            T = np.vstack([T, [0, 0, 0, 1]])

            T_rel = T0_inv @ T
            t_rel = T_rel[:3, 3] * 1000  # en mm

            print(f"Tag {id}: ΔX={t_rel[0]:.1f}, ΔY={t_rel[1]:.1f}, ΔZ={t_rel[2]:.1f}")

            if id in tag_centers and 0 in tag_centers:
                cv2.line(undistorted, tag_centers[0], tag_centers[id], (255, 0, 255), 2)
                cv2.putText(undistorted, f"0->{id}: {np.linalg.norm(t_rel[:2]):.1f} mm",
                            (10, 30 + 30 * id), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)

        last_print_time = time.time()

    cv2.imshow("AprilTag Detection", undistorted)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()