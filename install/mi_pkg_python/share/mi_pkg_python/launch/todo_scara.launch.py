import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction, LogInfo
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    pkg_name = 'mi_pkg_python'
    
    # 1. OBJETOS DE LANZAMIENTO
    
    # A) Gemelo Digital (Rviz2 + URDF)
    # Incluimos tu launch existente
    launch_gemelo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory(pkg_name), 'launch', 'proyecto_rviz2.launch.py')
        )
    )

    # B) Cámara (AprilTags)
    # Se inicia rápido para que la imagen esté lista
    nodo_camara = Node(
        package=pkg_name,
        executable='p_orientacion2juntas',
        name='nodo_vision_apriltag',
        output='screen'
    )

    # C) Conexión Arduino (Driver)
    # Le damos tiempo para establecer la conexión serial
    nodo_arduino = Node(
        package=pkg_name,
        executable='p_mega',
        name='driver_arduino',
        output='screen'
    )

    # D) Secuencia de Pasos (FSM - Lógica)
    # Este debe ser el ÚLTIMO en iniciar
    nodo_secuencia = Node(
        package=pkg_name,
        executable='p_secuencia', # Asegúrate que así se llame en setup.py
        name='maquina_estados_fsm',
        output='screen'
    )

    # 2. ORQUESTACIÓN CON RETRASOS (TIMERS)
    
    # El Arduino arranca 3 segundos después de Rviz/Cámara para asegurar estabilidad USB
    delay_arduino = TimerAction(
        period=3.0,
        actions=[LogInfo(msg="Iniciando Driver Arduino..."), nodo_arduino]
    )

    # La Secuencia arranca 6 segundos después del inicio
    # Esto da tiempo a que la cámara detecte tags y el Arduino confirme conexión
    delay_secuencia = TimerAction(
        period=6.0,
        actions=[LogInfo(msg="Iniciando Lógica de Control..."), nodo_secuencia]
    )

    return LaunchDescription([
        # Inician de inmediato
        launch_gemelo,
        nodo_camara,
        
        # Inician con retraso
        delay_arduino,
        delay_secuencia
    ])