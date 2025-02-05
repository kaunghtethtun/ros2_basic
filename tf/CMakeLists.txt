cmake_minimum_required(VERSION 3.8)
project(tf)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(turtlesim REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(static src/static_tf.cpp)
ament_target_dependencies(static rclcpp geometry_msgs tf2 tf2_ros)

add_executable(dynamic src/dynamic_tf.cpp)
ament_target_dependencies(dynamic rclcpp geometry_msgs tf2 tf2_ros turtlesim) 

add_executable(listen src/tf_listener.cpp)
ament_target_dependencies(listen rclcpp geometry_msgs tf2 tf2_ros turtlesim) 

add_executable(fixed src/fixed_frame.cpp)
ament_target_dependencies(fixed rclcpp geometry_msgs tf2 tf2_ros) 

add_executable(dynamic_fixed src/dynamic_fixed_frame.cpp)
ament_target_dependencies(dynamic_fixed rclcpp geometry_msgs tf2 tf2_ros) 

add_executable(robotpose src/robot_pose.cpp)
ament_target_dependencies(robotpose rclcpp geometry_msgs tf2 tf2_ros) 

install(TARGETS
  static
  dynamic
  listen
  fixed
  dynamic_fixed
  robotpose
 DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
 launch
 DESTINATION share/${PROJECT_NAME}/
)

ament_package()
