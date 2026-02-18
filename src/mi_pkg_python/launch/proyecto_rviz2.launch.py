from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import Command
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution

# --- IMPORT NUEVO Y NECESARIO ---
from launch_ros.parameter_descriptions import ParameterValue

def generate_launch_description():
    # 1. URDF de los SCARAs
    xacro_file = PathJoinSubstitution([
        FindPackageShare("mi_pkg_python"),
        "urdf",
        "ensamblaje.urdf.xacro"
    ])

    # 2. URDF de la Banda Transportadora
    banda_file = PathJoinSubstitution([
        FindPackageShare("mi_pkg_python"),
        "urdf",
        "banda.urdf" 
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
            # --- SE APLICA EL ParameterValue AQUÍ ---
            {"robot_description": ParameterValue(robot1_description, value_type=str)},
            {"publish_robot_description": True},
        ],
        remappings=[
            ("/joint_states", "joint_states"),
            ("/robot_description", "robot_description"),
        ],
    )

    static_r1 = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_r1_world",
        output="screen",
        arguments=["0.1", "0.5", "0.25", "-1.57", "0", "0", "world", "r1_base_link"],
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
            # --- SE APLICA EL ParameterValue AQUÍ ---
            {"robot_description": ParameterValue(robot2_description, value_type=str)},
            {"publish_robot_description": True},
        ],
        remappings=[
            ("/joint_states", "joint_states"),
            ("/robot_description", "robot_description"),
        ],
    )
    
    static_r2 = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_r2_world",
        output="screen",
        arguments=["0.1", "-0.5", "0.25", "1.57", "0", "0", "world", "r2_base_link"],
    )

    # --- Banda Transportadora ---
    banda_description = Command(["xacro ", banda_file])

    rsp_banda = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher_banda",
        namespace="banda",
        output="screen",
        parameters=[
            # --- SE APLICA EL ParameterValue AQUÍ ---
            {"robot_description": ParameterValue(banda_description, value_type=str)},
            {"publish_robot_description": True},
        ],
        remappings=[
            ("/joint_states", "joint_states"),
            ("/robot_description", "robot_description"),
        ],
    )

    #static_banda = Node(
    #    package="tf2_ros",
    #    executable="static_transform_publisher",
    #    name="static_banda_world",
    #    output="screen",
        # NUEVOS VALORES: [X, Y, Z, Yaw, Pitch, Roll, pad_frame, child_frame]
    #    arguments=["0.4", "-0.5", "0", "0", "0", "0", "world", "banda_base_link"],
    #)

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