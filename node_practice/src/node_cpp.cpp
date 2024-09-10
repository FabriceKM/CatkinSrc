// The executable file is in the directory: "~/catkin_ws/devel/lib/node_practice"
// To execute the executable file, run roscore in another terminal, move to the above directory and run the command "./node_cpp"
// Another way to execute the node is to move in "~/catkin_ws" directory and run the command "rosrun node_practice(package name) node_cpp"

#include "ros/ros.h"

int main(int argc, char **argv)
{
    // Initialize the node, and give it a name
    ros::init(argc, argv, "node_cpp_practice");
    ros::NodeHandle n;

    // Add a comment that will be printed on the terminal when the node is running
    ROS_INFO("Hello, node is started");
    ros::Duration(3.0).sleep();

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        ROS_INFO("This is a node running in c++");
        ros::spinOnce();
        loop_rate.sleep();
    }

    ROS_INFO("Finished to execute the node, Exit now!");
}