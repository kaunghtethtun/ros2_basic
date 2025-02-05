#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

int i = 0;
class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("minimal_publisher")
    {
      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      
      auto message = geometry_msgs::msg::Twist();
      if (i <= 0)
      {
        for(int a = 0; a < 8; a++)
        {
          message.linear.x = 2.0;
          message.angular.z = 0.0;
          i++;
        }
      }
      else if (i > 0)
      {
        for (int b = 0; b < 4; b++)
        {
          message.linear.x = 0.0;
          message.angular.z = 1.57;
          i--;
        }
      }
      
      publisher_->publish(message);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.linear.x);
      
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}