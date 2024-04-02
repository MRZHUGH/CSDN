cmake_minimum_required(VERSION 2.8.3)
project(tfsensors)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  tf
)

# find_package(Eigen REQUIRED)
find_package(OpenCV REQUIRED)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES tfsensors
#  CATKIN_DEPENDS geometry_msgs roscpp tf
#  DEPENDS system_lib
)

include_directories(include

)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  # ${Eigen_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

include_directories("/usr/include/eigen3")

file(GLOB_RECURSE cpp_files
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        )
add_library(tfsensorscpp ${cpp_files})


add_executable(tf_broadcaster main/tf_broadcaster.cpp)
target_link_libraries(tf_broadcaster
        ${catkin_LIBRARIES}
        ${OpenCV_LIBRARIES}
        tfsensorscpp
        )