import launch
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():

    # Defines our components
    odom_to_nav_path_node = ComposableNode(
        package='msbot_application',
        plugin='msbot::OdomToNavPathNode',
        name='odom_to_path',
    )

    # Add our component nodes in container
    container = ComposableNodeContainer(
        name='msbot_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[odom_to_nav_path_node]
    )

    return launch.LaunchDescription([container])
