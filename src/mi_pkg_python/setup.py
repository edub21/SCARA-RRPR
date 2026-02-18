from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'mi_pkg_python'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
    ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
    ('share/' + package_name, ['package.xml']),
    ('share/' + package_name + '/urdf', ['urdf/ensamblaje.urdf']),
    ('share/' + package_name + '/urdf', ['urdf/banda.urdf']),
    ('share/' + package_name + '/urdf', ['urdf/ensamblaje.urdf.xacro']),
    ('share/' + package_name + '/urdf/meshes', [
        'urdf/meshes/base_link.STL',
        'urdf/meshes/brazo_link.STL',
        'urdf/meshes/antebrazo_link.STL',
        'urdf/meshes/efector_link.STL',
        'urdf/meshes/banda_base_link.STL',
        'urdf/meshes/banda_link.STL'
    ]),
    ('share/' + package_name + '/launch', ['launch/visualizar_rviz.launch.py']),
    ('share/' + package_name + '/launch', ['launch/proyecto_rviz2.launch.py']),
    ('share/' + package_name + '/launch', ['launch/todo_scara.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ros22026',
    maintainer_email='ros22026@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
       'publicador1 = mi_pkg_python.publicador:main',
       'suscriptor1 = mi_pkg_python.suscriptor:main',
       'apriltag_1 = mi_pkg_python.apriltag_1:main',
       'apriltag_2 = mi_pkg_python.apriltag_2:main',
       'servidor_1 = servicios.srv_servidor:main',
       'cliente_1 = servicios.srv_cliente:main',
       'puente_mqtt = mi_pkg_python.puente_mqtt:main',
	    'action_servidor = acciones.action_server:main',
       'action_cliente  = acciones.action_client:main',       
        '0_tf2  = mi_pkg_python.0_tf2:main',
        '0_urdf_sub  = mi_pkg_python.0_urdf_sub:main',
        '0_urdf_pub  = mi_pkg_python.0_urdf_pub:main',
        'urdf_mqtt  = mi_pkg_python.urdf_mqtt:main',
        'p_set  = proyecto.set:main',
        'p_puente  = proyecto.puente_mqtt_ros2:main',
        'p_prueba  = proyecto.prueba_publicador:main',
        'p_fsm  = proyecto.fsm:main',
        'p_vision2riz  = proyecto.vision_to_rviz:main',
        'p_orientacion2juntas  = proyecto.orientacion_juntas:main',
        'p_orientacion2juntasSCARA2  = proyecto.orientacion_juntas_Scara2:main',
        'p_mega  = proyecto.mega:main',
        'cubo_publisher  = proyecto.CuboPublisher:main',
        
        ],       
    },
)
