
#include "ros/ros.h"
#include "std_msgs/String.h"


// 接收到订阅的消息，进入回调函数
void chatterCallback(const std_msgs::String::ConstPtr & msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str()); // 将接收的消息打印出来
}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"listener"); // 初始化一个名为listener的节点
	ros::NodeHandle n; // 创建名为n的节点句柄
	// 创建一个Subscriber的话题，注册回调函数chatterCallback
	ros::Subscriber sub=n.subscribe("chatter", 1000, chatterCallback);
	// 循环等待回调函数
	ros::spin();
	return 0;
}  

