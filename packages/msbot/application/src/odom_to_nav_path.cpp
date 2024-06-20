#include <chrono>

#include "odom_to_nav_path/odom_to_nav_path_node.hpp"
#include "std_msgs/msg/string.hpp"
#include "rclcpp_components/register_node_macro.hpp"

namespace msbot 
{

  using namespace std::chrono_literals;
  using std::placeholders::_1;

  OdomToNavPathNode::OdomToNavPathNode(rclcpp::NodeOptions options)
  : Node("publisher_node", options), count_(0)
  {
    publisher_ = create_publisher<nav_msgs::msg::Path>("msbot/path", 10);
    odom_subscription_ = create_subscription<nav_msgs::msg::Odometry>(
      "msbot/odometry", 10, std::bind(&OdomToNavPathNode::on_odom_msg_callback, this, _1));

  }

  void OdomToNavPathNode::on_odom_msg_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
  {
    geometry_msgs::msg::PoseStamped pose_stamped;
    pose_stamped.header.stamp = msg->header.stamp;
    pose_stamped.header.frame_id = msg->header.frame_id;
    pose_stamped.pose = msg->pose.pose;

    global_path_.poses.push_back(pose_stamped);
    global_path_.header.stamp = msg->header.stamp;
    global_path_.header.frame_id = msg->header.frame_id;
    publisher_->publish(global_path_);
  }


} // namespace msbot

RCLCPP_COMPONENTS_REGISTER_NODE(msbot::OdomToNavPathNode)
