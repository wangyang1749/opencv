#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <opencv2\imgproc\types_c.h>
// #pragma comment(lib, "opencv_world411dll.lib")在mingw不能使用
using namespace std;
using namespace cv;

int main(){
	//读取本地的一张图片便显示出来
	Mat img = imread("E:\\temp\\02.png",IMREAD_GRAYSCALE);
	namedWindow("opencvdemo");

	imshow("opencvdemo", img);

	Mat output;
	cvtColor(img,output,CV_BGR2GRAY);
	imshow("output",output);
	imwrite("D:/temp/001.png",output);

	//等待用户按键
	waitKey(0);
	return 0;
}