
#include "config.h"

// config_file是输入，R和t是返回值
void readParameters(std::string config_file, cv::Mat& R, cv::Mat& t)
{
    cv::FileStorage fsSettings(config_file, cv::FileStorage::READ);
    if(!fsSettings.isOpened())
    {
        std::cerr << "ERROR: Wrong path to settings" << std::endl;
    }

    cv::Mat cv_R, cv_t;
    fsSettings["lidar_to_imu_rotation"] >> cv_R;
    fsSettings["lidar_to_imu_translation"] >> cv_t;

    R = cv_R;
    t = cv_t;

    fsSettings.release();
}