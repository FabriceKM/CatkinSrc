// The executable file is in the directory: "~/catkin_ws/devel/lib/node_practice"
// To execute the executable file, run roscore in another terminal, move to the above directory and run the command "./subscriber_cpp"
// Another way to execute the node is to move in "~/catkin_ws" directory and run the command "rosrun node_practice(package name) subscriber_cpp"

#include "ros/ros.h"
#include "std_msgs/String.h"


void Callback_function(const std_msgs::String& msg)
{
    ROS_INFO("This is the message I heard: %s", msg.data.c_str());
}


int main(int argc, char **argv)
{
    // Initialize the node, and give it a name
    ros::init(argc, argv, "subscriber_cpp");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("message_topic", 1000, Callback_function);
    ros::spin();

    return 0;
}