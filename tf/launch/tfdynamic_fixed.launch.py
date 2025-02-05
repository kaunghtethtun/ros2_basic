from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            executable='dynamic',
            package='tf',
            parameters=[{'turtlename':'turtle1'}]
        ),
        Node(
            executable='turtlesim_node',
            package='turtlesim',
        ),
        Node(
            executable='dynamic',
            package='tf',
            parameters=[{'turtlename':'turtle2'}]
        ),
        Node(
            executable='dynamic_fixed',
            package='tf'
        ),
    ])