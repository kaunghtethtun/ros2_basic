#include <chrono>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "interface_test/msg/point.hpp"

using namespace std::chrono_literals;
int a = 0;
/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("interface_testpublisher")
    {
      publisher_ = this->create_publisher<interface_test::msg::Point>("Int", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto msg = interface_test::msg::Point();
      msg.r = a;
      msg.center.x = 34.5;
      RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: ' " << msg.r << " ' , " << msg.center.x);
      publisher_->publish(msg);
      a++;
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<interface_test::msg::Point>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}