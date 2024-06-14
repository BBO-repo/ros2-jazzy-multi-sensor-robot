FROM osrf/ros:jazzy-desktop-full

WORKDIR /workspace

RUN apt update && apt -y dist-upgrade && apt install -y \
  nano git wget software-properties-common \
  ros-jazzy-ros2-control ros-jazzy-ros2-controllers \
  ros-jazzy-gz-ros2-control ros-jazzy-ros-gz \
  ros-jazzy-ackermann-msgs ros-jazzy-geometry2 \
  ros-jazzy-joint-state-publisher-gui ros-jazzy-imu-tools \
  ros-jazzy-robot-localization ros-jazzy-geographic-msgs \
  && rm -rf /var/lib/apt/lists/*

# RUN add-apt-repository -y ppa:borglab/gtsam-release-4.0 && \
#   apt install -y libgtsam-dev libgtsam-unstable-dev
# RUN apt-get install libgtsam4 libpcl-dev
# those packag are not available for jazzy
# ros-humble-gazebo-ros-pkgs ros-humble-velodyne-simulator

RUN echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
RUN echo "export GZ_SIM_RESOURCE_PATH=/workspace/packages/msbot/description/models" >> ~/.bashrc

# CMD ["/bin/bash"]
