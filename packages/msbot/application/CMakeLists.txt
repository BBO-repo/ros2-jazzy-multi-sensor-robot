cmake_minimum_required(VERSION 3.5)
project(msbot_application)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(nav_msgs REQUIRED)

include_directories(include)

add_library(odom_to_nav_path SHARED
            src/odom_to_nav_path.cpp)

ament_target_dependencies(odom_to_nav_path rclcpp rclcpp_components nav_msgs)

rclcpp_components_register_node(odom_to_nav_path PLUGIN "msbot::OdomToNavPathNode" EXECUTABLE odom_to_path)

# This package installs libraries without exporting them.
# Export the library path to ensure that the installed libraries are available
ament_environment_hooks("${ament_cmake_package_templates_ENVIRONMENT_HOOK_LIBRARY_PATH}")

install(TARGETS
  odom_to_nav_path
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Install project launch files
install(
  DIRECTORY
    launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
