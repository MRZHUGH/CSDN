#! /usr/bin/python
# -*- encoding: utf-8 -*-

import rospy
from std_msgs.msg import String

# talker 函数
def talker():
    pub = rospy.Publisher('chatter', String, queue_size=10)
    rospy.init_node('talker', anonymous=True) # 初始化节点
    rate = rospy.Rate(10) # 发布频率 10 hz
    count = 0
    while not rospy.is_shutdown():
        hello_str = "hello world " + str(count)
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        count+=1
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass