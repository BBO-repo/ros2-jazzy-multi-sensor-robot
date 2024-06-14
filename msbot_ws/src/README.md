ROS2 workspace and packages and kept seperated, to use the msbot package run
run ln -s /workspace/package/msbot /workspace/msbot_ws/src
cd /workspace/package/msbot
colcon build -symlink-install
