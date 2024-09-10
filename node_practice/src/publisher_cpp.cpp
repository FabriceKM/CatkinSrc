// The executable file is in the directory: "~/catkin_ws/devel/lib/node_practice"
// To execute the executable file, run roscore in another terminal, move to the above directory and run the command "./publisher_cpp"
// Another way to execute the node is to move in "~/catkin_ws" directory and run the command "rosrun node_practice(package name) publisher_cpp"

#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // Initialize the node, and give it a name
    ros::init(argc, argv, "publisher_cpp");
    ros::NodeHandle n; // object that allows you to interact in the easiest way with the node
    ros::Publisher pub = n.advertise<std_msgs::String>("message_topic", 1000);

    // Add a comment that will be printed on the terminal when the node is running
    ROS_INFO("Hello, node is started");

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        std_msgs::String msg;
        msg.data = "This is the message to publish: Hello!!!";

        // Publish the message on topic /message_topic
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
}