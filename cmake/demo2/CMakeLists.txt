# 工程配置
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
set(OpenCV_DIR  /home/wy/softwere/opencv/lib/cmake/opencv4)
# 引入外部依赖
find_package(OpenCV REQUIRED)
# 头文件变量的引入,如果/usr/local/include 中存在可以不用引入
# include_directories( ${OpenCV_INCLUDE_DIRS} )
# 添加执行文件
add_executable( DisplayImage src/DisplayImage.cpp )
# 链接库文件
target_link_libraries( DisplayImage ${OpenCV_LIBS} )