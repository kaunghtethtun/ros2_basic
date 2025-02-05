cmake_minimum_required(VERSION 3.8)
project(custom)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Num.msg"
  "srv/Add.srv"
)

ament_export_dependencies(rosidl_default_runtime)

rosidl_get_typesupport_target(cpp_typesupport_target 
  ${PROJECT_NAME} "rosidl_typesupport_cpp"
)


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

add_executable(pubInt src/testmsg.cpp)
ament_target_dependencies(pubInt rclcpp)
target_link_libraries(pubInt "${cpp_typesupport_target}")

add_executable(client src/client.cpp)
ament_target_dependencies(client rclcpp)
target_link_libraries(client "${cpp_typesupport_target}")

add_executable(server src/server.cpp)
ament_target_dependencies(server rclcpp)
target_link_libraries(server "${cpp_typesupport_target}")

add_executable(param src/testparam.cpp)
ament_target_dependencies(param rclcpp)

# add_executable(param_1 src/testparam_1.cpp)
# ament_target_dependencies(param_1 rclcpp)

install(TARGETS
  pubInt
  client
  server
  param
  DESTINATION lib/${PROJECT_NAME})

ament_package()
