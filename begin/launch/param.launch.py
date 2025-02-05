from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            executable='param',
            package='custom',
            output='screen',
            emulate_tty=False,
            parameters=[{'param':2}],
        ),
    ])