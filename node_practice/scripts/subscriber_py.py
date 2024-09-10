#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def Callback_py(msg):
    rospy.loginfo("This is the message I heard: ")
    rospy.loginfo(msg)

if __name__ == '__main__':
    rospy.init_node("subscriber_py")

    sub = rospy.Subscriber("message_topic", String, Callback_py)
    rospy.spin()