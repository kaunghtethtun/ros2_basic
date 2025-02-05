from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='sim'
        ),
        Node(
            package='tf',
            executable='dynamic',
            name='dynamic1',
            parameters=[
                {'turtlename': 'turtle1'}
            ]
        ),
        DeclareLaunchArgument(
            'target_frame', default_value='turtle1',
            description='Target frame name.'
        ),
        Node(
            package='tf',
            executable='dynamic',
            name='dynamic2',
            parameters=[
                {'turtlename': 'turtle2'}
            ]
        ),
        # Node(
        #     package='tf',
        #     executable='listen',
        #     name='listener',
        #     parameters=[
        #         {'target_frame': LaunchConfiguration('target_frame')}
        #     ]
        # ),
    ])