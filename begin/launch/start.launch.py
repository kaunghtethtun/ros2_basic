from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            executable='pub',
            package='begin',
            name='Publisher',
            namespace='pub',
            output='screen',
            emulate_tty=True
        ),
        Node(
            executable='sub',
            package='begin',
            name='Sublisher',
            namespace='pub',
            output='screen'
        ),

    ])