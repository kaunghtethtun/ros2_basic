cmake_minimum_required(VERSION 3.8)
project(begin)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom REQUIRED)
find_package(interface_test)

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

add_executable(pub src/publisher.cpp)
ament_target_dependencies(pub rclcpp std_msgs)

add_executable(sub src/subscriber.cpp)
ament_target_dependencies(sub rclcpp std_msgs)

add_executable(intP src/intpub.cpp)
ament_target_dependencies(intP rclcpp std_msgs)

add_executable(vel src/turtle_vel.cpp)
ament_target_dependencies(vel rclcpp geometry_msgs)

add_executable(square src/square1.cpp)
ament_target_dependencies(square rclcpp geometry_msgs)

add_executable(pubCus src/customint.cpp)
ament_target_dependencies(pubCus rclcpp custom)

add_executable(simple src/testPub.cpp)
ament_target_dependencies(simple rclcpp interface_test)

add_executable(class src/noclass.cpp)
ament_target_dependencies(class rclcpp interface_test)

install(TARGETS
 pub
 sub
 intP
 vel
 square
 pubCus
 simple
 class
 DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
 launch
 DESTINATION share/${PROJECT_NAME}/
)
ament_package()
