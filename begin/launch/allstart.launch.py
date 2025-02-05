from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            executable='turtlesim_node',
            package='turtlesim',
            name='turtle1',
            output='screen'
        ),
        Node(
            executable='turtle_teleop_key',
            package='turtlesim',
            name='teleop',
            output='screen',
            prefix=['gnome-terminal --']
        ),
    ])