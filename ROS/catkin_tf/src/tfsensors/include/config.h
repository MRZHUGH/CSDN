

#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H

#include <iostream>

#include <eigen3/Eigen/Dense>  // 小tips：须在 #include <opencv2/core/eigen.hpp> 顺序之前

#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

// #include <vector>

void readParameters(std::string config_file, cv::Mat& R, cv::Mat& t);
#endif