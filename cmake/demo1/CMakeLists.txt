# 工程配置
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
set(OpenCV_INCLUDE_DIRS /usr/local/include)
set(OpenCV_LIBS opencv_core opencv_highgui opencv_imgcodecs)
# 头文件变量的引入
include_directories( ${OpenCV_INCLUDE_DIRS} )
# 添加执行文件
add_executable( DisplayImage src/DisplayImage.cpp )
# 链接库文件
target_link_libraries( DisplayImage ${OpenCV_LIBS} )