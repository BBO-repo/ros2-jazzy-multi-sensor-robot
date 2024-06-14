cmake_minimum_required(VERSION 3.5)

# Following directive defines the project name.
project(msbot_gazebo)

find_package(ament_cmake REQUIRED)
find_package(msbot_description REQUIRED)

# Following 'install' directive ensures that the 'worlds' subfolder
# will be copied to the 'share/msbot_gazebo/worlds'
# subfolder of the installation directory.
install(
  DIRECTORY worlds/
  DESTINATION share/${PROJECT_NAME}/worlds
)

# Following directives are used when testing.
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()