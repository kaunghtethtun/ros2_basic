#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;
std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("simple_publisher");
std::shared_ptr<rclcpp::TimerBase> timer_;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

void timer_callback()
    {
      std::string param = node->get_parameter("param").get_parameter_value().get<std::string>();
      RCLCPP_INFO(rclcpp::get_logger("string"), "Hello %s", param.c_str());
    }

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  node->declare_parameter("param", "World!");
  timer_ = node->create_wall_timer(500ms, timer_callback);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}