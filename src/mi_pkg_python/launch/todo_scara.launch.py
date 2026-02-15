import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction, LogInfo
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    pkg_name = 'mi_pkg_python'
    
    # --- 1. DEFINICIÓN DE NODOS Y LAUNCHES ---

    # Gemelo Digital (Rviz2)
    launch_gemelo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory(pkg_name), 'launch', 'proyecto_rviz2.launch.py')
        )
    )

    # Cámara 1
    nodo_camara_1 = Node(
        package=pkg_name,
        executable='p_orientacion2juntas',
        name='nodo_vision_scara_1',
        output='screen'
    )

    # Cámara 2 (Nueva)
    nodo_camara_2 = Node(
        package=pkg_name,
        executable='p_orientacion2juntasSCARA2',
        name='nodo_vision_scara_2',
        output='screen'
    )

    # Driver Arduino
    nodo_arduino = Node(
        package=pkg_name,
        executable='p_mega',
        name='driver_arduino',
        output='screen'
    )

    # Lógica de Control (FSM)
    nodo_secuencia = Node(
        package=pkg_name,
        executable='p_fsm',
        name='maquina_estados_fsm',
        output='screen'
    )

    # --- 2. ORQUESTACIÓN CON INTERVALOS DE 5 SEGUNDOS ---

    # T=5s: Inician AMBAS cámaras a la par
    delay_camaras = TimerAction(
        period=5.0,
        actions=[
            LogInfo(msg=">> Iniciando SISTEMA DE VISIÓN (Cámara 1 y 2)..."),
            nodo_camara_1,
            nodo_camara_2
        ]
    )

    # T=10s: Inicia el Arduino (5s después de las cámaras)
    delay_arduino = TimerAction(
        period=10.0,
        actions=[
            LogInfo(msg=">> Iniciando DRIVER ARDUINO..."),
            nodo_arduino
        ]
    )

    # T=15s: Inicia la secuencia (5s después del Arduino)
    delay_secuencia = TimerAction(
        period=15.0,
        actions=[
            LogInfo(msg=">> Iniciando LÓGICA DE CONTROL FINAL..."),
            nodo_secuencia
        ]
    )

    return LaunchDescription([
        launch_gemelo,    # T=0
        delay_camaras,     # T=5 (Ambas cámaras juntas)
        delay_arduino,     # T=10
        delay_secuencia    # T=15
    ])