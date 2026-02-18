import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/edub/ros2_ws/src/mi_pkg_python/install/mi_pkg_python'
