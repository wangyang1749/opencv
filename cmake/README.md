# Cmake的使用
```
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
```

# find_package(OpenCV REQUIRED)的使用
```
# 工程配置
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
set(OpenCV_DIR  /home/wy/softwere/opencv/lib/cmake/opencv4）
# 引入外部依赖
find_package(OpenCV REQUIRED)
# 头文件变量的引入
include_directories( ${OpenCV_INCLUDE_DIRS} )
# 添加执行文件
add_executable( DisplayImage src/DisplayImage.cpp )
# 链接库文件
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
```
+ `set(OpenCV_DIR  /home/wy/Documents/opencv/opencv4)`必须指定为安装opencv的路径中包含` OpenCVConfig.cmake`
+ 否则出现 ` OpenCV: Include directory doesn't exist: '/home/wy/include/opencv4'.`

# 将库文件拷贝到Linux的系统目录下
> 如果不拷贝存在的问题
```
./main: error while loading shared libraries: libopencv_core.so.4.2: cannot open shared object file: No such file or directory
```
> 此时可以设置 `export LD_LIBRARY_PATH='/home/wy/softwere/opencv/lib'`临时指定动态库的位置
> 拷贝时注意的问题


# Refreences
+ <https://cmake.org/cmake/help/v3.16/>
+ <https://www.cnblogs.com/newneul/p/8364924.html>

# 扩展
+ autotools 
+ camke 
+ qmake