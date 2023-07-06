
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include "math.h"
#include "config.h"

// #include <opencv2/opencv.hpp> //config.h已经包含了

template <typename T>
T readParam(ros::NodeHandle &n, std::string name)
{
    // std::cout << name <<std::endl;
    T ans;
    if (n.getParam(name, ans))
    {
    ROS_INFO_STREAM("Loaded " << name << ": " << ans);
    }
    else
    {
    ROS_ERROR_STREAM("Failed to load " << name);
    n.shutdown();
    }
    return ans;
}


int main(int argc, char** argv)
{

    ros::init(argc, argv, "tf_publisher");//初始化ROS节点与节点名称
    ros::NodeHandle n;                    //创建节点的句柄
    
    ros::NodeHandle pnh("~");

    std::string config_file;
    config_file = readParam<std::string>(pnh, "config_file");
    cv::Mat R, t;
    readParameters(config_file, R, t);

    Eigen::Matrix3d eigen_R;
    Eigen::Vector3d eigen_t;
    cv::cv2eigen(R, eigen_R);
    cv::cv2eigen(t, eigen_t);
    Eigen::Vector3d rpy = eigen_R.matrix().eulerAngles(2,1,0);

    ros::Rate loop_rate(100);             //设定节点运行的频率,与loop.sleep共同使用

    tf::TransformBroadcaster broadCaster; //创建TransformBroadcaster对象(tf广播器)，是用来发布tf变换树;
    
    tf::Transform lidar2base;             //激光雷达坐标系lidar_link;创建一个Transform对象,用于描述两个坐标系之间的转化关系;
    tf::Quaternion q;
    // M_PI = π; M_PI/2 = π/2;
    q.setRPY(M_PI*rpy[0], M_PI*rpy[1], M_PI*rpy[2]);              //RPY欧拉角(zyx),外参的旋转坐标
                                       
    lidar2base.setRotation(q);
    lidar2base.setOrigin(tf::Vector3(eigen_t[0], eigen_t[1], eigen_t[2])); // 平移坐标, lidar在base的xyz位置

    while (n.ok())
    {
        // 循环发布坐标变换
        broadCaster.sendTransform(tf::StampedTransform(lidar2base,ros::Time::now(),"base_link","lidar_link"));

        loop_rate.sleep();
    }
    return 0;
}
