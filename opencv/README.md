g++ .\main.cpp -I "../build/include" -static ../build/lib/libopencv_world411dll.a
g++ .\main.cpp -I "../build/include" -L ../build/lib -lopencv_world411dll
# 创建和清理mat空间
Mat mat(height,width,CV_8UC3)
创建一个height*width的矩阵，CV_8UC3数组的数据类型(无符号类型)

mat.create(rows,cols,CV_8UC1);
如果之前有数据将释放
release或者析构函数释放

isContinuous()判断存储空间是连续的吗


