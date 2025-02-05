#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;
std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>> publisher_;
std::shared_ptr<rclcpp::Publisher<std_msgs::msg::Int32>> pub_;
std::shared_ptr<rclcpp::TimerBase> timer_;
size_t count_;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

void timer_callback()
    {
      auto message = std_msgs::msg::String();
      message.data = "Hello, world! " + std::to_string(count_++);
      RCLCPP_INFO(rclcpp::get_logger("string"), "Publishing: '%s'", message.data.c_str());
      auto msg = std_msgs::msg::Int32();
      msg.data = 30;
      RCLCPP_INFO(rclcpp::get_logger("Int"), "Publishing: '%d'", msg.data);
      pub_->publish(msg);
      publisher_->publish(message);
    }

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("simple_publisher");
  publisher_ = node->create_publisher<std_msgs::msg::String>("topic", 10);
  pub_ = node->create_publisher<std_msgs::msg::Int32>("int", 10);
  timer_ = node->create_wall_timer(500ms, timer_callback);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}