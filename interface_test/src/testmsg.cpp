#include <chrono>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "interface_test/msg/cusint.hpp"

using namespace std::chrono_literals;
int a = 0;
/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class Publisher : public rclcpp::Node
{
  public:
    Publisher()
    : Node("Custompublisher")
    {
      publisher_ = this->create_publisher<interface_test::msg::Cusint>("Int", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&Publisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto msg = interface_test::msg::Cusint();
      msg.a = a;
      RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: ' " << msg.a << " '");
      publisher_->publish(msg);
      a++;
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<interface_test::msg::Cusint>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Publisher>());
  rclcpp::shutdown();
  return 0;
}