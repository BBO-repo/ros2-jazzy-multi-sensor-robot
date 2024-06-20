#ifndef ODOM_TO_NAV_PATH_HPP_
#define ODOM_TO_NAV_PATH_HPP_

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "nav_msgs/msg/path.hpp"

namespace msbot 
{
  class OdomToNavPathNode : public rclcpp::Node
  {
  public:
    OdomToNavPathNode(rclcpp::NodeOptions options);

  private:
    size_t count_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr publisher_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscription_;
    void on_odom_msg_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    nav_msgs::msg::Path global_path_;
  };
}
#endif  // ODOM_TO_NAV_PATH_HPP_
