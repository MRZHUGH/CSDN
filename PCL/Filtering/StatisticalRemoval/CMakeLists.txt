cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(StatisticalRemoval)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories((${PCL_LIBRARY_DIRS}))
add_definitions(${PCL_DEFINTIONS})

add_executable(StatisticalRemoval statistical_removal.cpp)
target_link_libraries(StatisticalRemoval ${PCL_LIBRARIES})