#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_msgs/TFMessage.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

void poseCallback(const geometry_msgs::TransformStamped& msg)
{
    static tf2_ros::TransformBroadcaster br;
    geometry_msgs::TransformStamped transformStamped;

    transformStamped.header.stamp = ros::Time::now();
    transformStamped.header.frame_id = "world";
    transformStamped.child_frame_id = "gripper_connector";

    transformStamped.transform.translation.x;
    transformStamped.transform.translation.y;
    transformStamped.transform.translation.z;

    tf2::Quaternion q;
    q.setRPY(0, 0, 0);

    transformStamped.transform.rotation.x = q.x();
    transformStamped.transform.rotation.y = q.y();
    transformStamped.transform.rotation.z = q.z();
    transformStamped.transform.rotation.w = q.w();

    br.sendTransform(transformStamped);
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "tcp_broadcaster");

    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/tf", 10, poseCallback);
    
    ros::spin();
    return 0;
}