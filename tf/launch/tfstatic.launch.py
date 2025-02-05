from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            executable='static_transform_publisher',
            package='tf2_ros',
            name="lidar",
            arguments=['--x', '3', '--y','4', '--z', '5' ,'--qx', '0', '--qy', '0', '--qz', '0', '--qw', '20', '--frame-id','robot', '--child-frame-id', 'lidar']
        ),
        Node(
            executable='static_transform_publisher',
            package='tf2_ros',
            name="camera",
            arguments=['--x', '3', '--y','4', '--z', '10' ,'--qx', '0', '--qy', '0', '--qz', '0', '--qw', '20', '--frame-id','robot', '--child-frame-id', 'camera']
        ),
    ])