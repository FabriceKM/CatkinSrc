#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def Callback_py(msg):
    rospy.loginfo("This is the message I heard: ")
    rospy.loginfo(msg)

if __name__ == '__main__':
    rospy.init_node("subscriber_py")
    pub = rospy.Publisher("message_topic", String, queue_size=1000)
    sub = rospy.Subscriber("message_topic_from_python", String, Callback_py)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        
        msg = String()
        msg.data = "This is the second message"
        pub.publish(msg)
        rate.sleep()