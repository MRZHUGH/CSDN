#include "ros/ros.h" //创建ROS节点必须包含的头文件，固定格式
#include "std_msgs/String.h" //节点中使用某种特定的消息类型
#include <sstream> // c++中用来处理面向流的输入和输出的标准库

int main(int argc,char **argv)
{
	ros::init(argc,argv,"talker"); // 初始化一个名为talker的节点，以后写其他的节点只要修改talker就行
	ros::NodeHandle n; // 创建名为n的节点句柄，自己写程序只要改n这个地方就行
	// ROS节点中发布话题的方式，chatter_pub是发布者实例，发布消息的类型是std_msgs/String的话题，
	// topic话题名称为chatter，队列大小为1000，n为访问实例，要修改的话就改提到的这几个地方
	ros::Publisher chatter_pub=n.advertise<std_msgs::String>("chatter", 1000);
	ros::Rate loop_rate(10); // 制定循环的频率，此处为10HZ，固定格式
	int count=0; // 进入节点的主循环，在节点未发生异常的情况下将一直在循环，固定格式
	while(ros::ok()) // 当Ctrl+c按下时，ros::ok()将会返回false，固定格式
	{
		// 初始化std_msgs::String类型的消息
		std_msgs::String msg;
		std::stringstream ss;
		ss<<"hello world"<<count;
		msg.data=ss.str(); // 用data来存储字符串
		// 发布消息
		ROS_INFO("%s",msg.data.c_str()); //ROS_INFO类似于cout和printf
		chatter_pub.publish(msg); // 发布封装完毕的消息msg
		// 循环等待回调函数
		ros::spinOnce(); // 用来处理节点订阅话题的所有回调函数
		// 按照循环频率延时，固定格式
		loop_rate.sleep();
		++count;
	}
	return 0;
}
