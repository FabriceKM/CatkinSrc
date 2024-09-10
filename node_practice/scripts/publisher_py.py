#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

if __name__ == '__main__':

    # Initialize the node and give it a name
    rospy.init_node("publisher_py")

    pub = rospy.Publisher("message_topic", String, queue_size=1000)

    rospy.loginfo("Hello, node python is started")

    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        msg = String()
        msg.data = "This is the message to publish in python: Hello !!!"
        pub.publish(msg)
        rate.sleep()