cmake_minimum_required(VERSION 2.8)

project(vsdebug)

set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_BUILD_TYPE "Release")
#-O3是一个优化选项，告诉编译器优化我们的代码。
#gcc -O0 -O1 -O2 -O3 四级优化选项及每级分别做什么优化
set(CMAKE_CXX_FLAGS "-O3")

#设置编译模式
set(CMAKE_CXX_STANDARD 11)
#设置lib路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 设置bin路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# include_directories("/usr/include/eigen3")

# 包含include中的头文件
include_directories(
${PROJECT_SOURCE_DIR}/include/
)
# 包含src中函数实现的cpp文件，生成动态链接库
add_library(${PROJECT_NAME} SHARED
# src/main.cpp
src/maths.cpp
)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/test)
# 添加main.cpp，编译成可执行文件
add_executable(main
src/main.cpp)
# main可执行文件添加链接库
target_link_libraries(main ${PROJECT_NAME})