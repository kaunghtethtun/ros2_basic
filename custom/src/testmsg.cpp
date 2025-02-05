#include <chrono>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "custom/msg/num.hpp"

using namespace std::chrono_literals;
int a = 0;
/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("Custompublisher")
    {
      publisher_ = this->create_publisher<custom::msg::Num>("Int", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto msg = custom::msg::Num();
      msg.num = a;
      RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: ' " << msg.num << " '");
      publisher_->publish(msg);
      a++;
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<custom::msg::Num>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}