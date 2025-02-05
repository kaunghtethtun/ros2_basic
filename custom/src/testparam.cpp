#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
  public:
    MinimalPublisher()
    : Node("testparam")
    {
      this->declare_parameter("param", 1);
      timer_ = this->create_wall_timer(
      1000ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

  private:

    void timer_callback()
    {
      int par = this->get_parameter("param").get_parameter_value().get<int>();
      RCLCPP_INFO(this->get_logger(), "%d", par);
      // std::vector<rclcpp::Parameter> all_new_parameters{rclcpp::Parameter("param",par)};
      // this->set_parameters(all_new_parameters);
      
      //msg.num = par;
    }
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}