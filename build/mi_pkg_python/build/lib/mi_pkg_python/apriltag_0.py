import cv2
from pupil_apriltags import Detector

def main():
    # Abre la cámara (0 = cámara predeterminada)
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("No se pudo acceder a la cámara.")
        return

    # Configurar el detector de AprilTags
    at_detector = Detector(
        families='tag36h11',
        nthreads=1,
        quad_decimate=1.0,
        quad_sigma=0.0,
        refine_edges=True,
        decode_sharpening=0.25,
        debug=False
    )

    # Nombre de la ventana
    window_name = 'AprilTag Detector - tag36h11'

    # Hacer la ventana redimensionable
    cv2.namedWindow(window_name, cv2.WINDOW_NORMAL)
    cv2.resizeWindow(window_name, 800, 600)  # Ancho x Alto en píxeles

    print("Cámara activa. Presiona 'q' para salir.")

    while True:
        ret, frame = cap.read()
        if not ret:
            print("No se pudo leer el frame.")
            break

        # Convertir imagen a escala de grises
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Detectar etiquetas AprilTag
        detections = at_detector.detect(gray)

        for detection in detections:
            tag_id = detection.tag_id
            print(f"Tag detectado: {tag_id}")

            # Dibujar un círculo en el centro del tag
            center = (int(detection.center[0]), int(detection.center[1]))
            cv2.circle(frame, center, 10, (0, 255, 0), 2)

        # Mostrar imagen con detecciones
        cv2.imshow(window_name, frame)

        # Salir si se presiona la tecla 'q'
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Liberar recursos
    cap.release()
    cv2.destroyAllWindows()
    print("Cámara cerrada.")

if __name__ == '__main__':
    main()