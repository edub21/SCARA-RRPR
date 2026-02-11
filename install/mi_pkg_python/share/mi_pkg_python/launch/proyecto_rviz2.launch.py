from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import Command
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution


def generate_launch_description():
    xacro_file = PathJoinSubstitution([
        FindPackageShare("mi_pkg_python"),
        "urdf",
        "ensamblaje.urdf.xacro"
    ])

    # --- Robot 1 (prefijo r1_) ---
    robot1_description = Command(["xacro ", xacro_file, " prefix:=r1_"])

    rsp1 = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        namespace="r1",
        output="screen",
        parameters=[
            {"robot_description": robot1_description},
            {"publish_robot_description": True},
        ],
        remappings=[
            ("/joint_states", "joint_states"),
            ("/robot_description", "robot_description"),
        ],
    )

    '''
    Agregar un GUI para mover las juntas, y agregar variable en el Launch
    description

    jsp1 = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
        name="joint_state_publisher_gui",
        namespace="r1",
        output="screen",
        remappings=[
            ("/joint_states", "joint_states"),
        ],
    )
    '''

    # Posición del robot 1 en el mundo (world -> r1_base_link)
    static_r1 = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_r1_world",
        output="screen",
        arguments=["-0.5", "0.5", "0", "-1.57", "0", "0", "world", "r1_base_link"],
    )

    # --- Robot 2 (prefijo r2_) ---
    robot2_description = Command(["xacro ", xacro_file, " prefix:=r2_"])

    rsp2 = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        namespace="r2",
        output="screen",
        parameters=[
            {"robot_description": robot2_description},
            {"publish_robot_description": True},
        ],
        remappings=[
            ("/joint_states", "joint_states"),
            ("/robot_description", "robot_description"),
        ],
    )
    # Posición del robot 2 en el mundo (separado 1 metro en X)
    static_r2 = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_r2_world",
        output="screen",
        arguments=["0.5", "-0.5", "0", "1.57", "0", "0", "world", "r2_base_link"],
    )

    # RViz2
    rviz = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen"
    )

    return LaunchDescription([
        rsp1, static_r1,
        rsp2, static_r2,
        rviz
    ])
