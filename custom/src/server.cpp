#include "rclcpp/rclcpp.hpp"
#include "custom/srv/add.hpp"

#include <memory>

void add(const std::shared_ptr<custom::srv::Add::Request> request,
          std::shared_ptr<custom::srv::Add::Response>      response)
{
  response->sum = request->a + request->b + request->c;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld" " c: %ld",
                request->a, request->b, request->c);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_ints_server");

  rclcpp::Service<custom::srv::Add>::SharedPtr service =
    node->create_service<custom::srv::Add>("add_ints", &add);
  
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add ints.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}