#include <iostream>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/project_inliers.h>

int main(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_projectd (new pcl::PointCloud<pcl::PointXYZ>);

    cloud->width = 5;
    cloud->height = 1;
    cloud->points.resize (cloud->width * cloud->height);

    for (auto& point: *cloud){
        point.x = 1024 * rand() / (RAND_MAX + 1.0F);
        point.y = 1024 * rand() / (RAND_MAX + 1.0F);
        point.z = 1024 * rand() / (RAND_MAX + 1.0F);

    }

    std::cerr << "Cloud before projection: " << std::endl;
    for (const auto& point: *cloud){
        std::cerr << "      " << point.x << " "
                              << point.y << " "
                              << point.z << std::endl;
    }

    pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients());
    coefficients->values.resize(4);
    coefficients->values[0] = coefficients->values[1] = 0;
    coefficients->values[2] = 1.0;
    coefficients->values[3] = 0;

    pcl::ProjectInliers<pcl::PointXYZ> proj;
    proj.setModelType (pcl::SACMODEL_PLANE);
    proj.setInputCloud (cloud);
    proj.setModelCoefficients (coefficients);
    proj.filter (*cloud_projectd);

    std::cerr << "Cloud after projection: " << std::endl;
    for (const auto& point: *cloud_projectd){
        std::cerr << "      " << point.x << " "
                              << point.y << " "
                              << point.z << std::endl;        
    }
    return (0);
}