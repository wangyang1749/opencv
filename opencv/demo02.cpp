#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <opencv2\imgproc\types_c.h>
using namespace std;
using namespace cv;
/*
    矩阵的掩膜操作->提高图像的对比度
    获取图像像素指针
     saturate_cast<uchar>()返回0~255之间的数
     I(i,j)=5*I(i,j)-[I(i-1,j)+I(i+1,j)+I(i,j-1)+I(i,j+1)]
 */
int main(){
	//读取本地的一张图片便显示出来
	Mat img = imread("E:\\temp\\02.png");
	namedWindow("opencvdemo");

	imshow("opencvdemo", img);

	int cols = (img.cols-1)*img.channels();
	int rows = img.rows;
	int offsetx = img.channels();
    Mat dst;
    dst=Mat::zeros(img.size(),img.type());

    // imshow("output0",dst);
    for(int row=1;row<rows-1;row++){
		const uchar * previous = img.ptr<uchar>(row);
        const uchar * current = img.ptr<uchar>(row-1);
        const uchar * next = img.ptr<uchar>(row+1);
        uchar* output = dst.ptr<uchar>(row);
       for(int col=offsetx;col<cols;col++){
            output[col] = saturate_cast<uchar>(5*current[col]-(current[col-offsetx]+current[col+offsetx]+previous[col]+next[col]));
        }
	}
    imshow("output",dst);
	//等待用户按键
    
    double t  =getTickCount();
    Mat output2 = Mat::zeros(img.size(),img.type());
	Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
    filter2D(img,output2,img.depth(),kernel);
    double timeconunt = (getTickCount()-t)/getTickFrequency();
    cout<<"time is "<<timeconunt<<endl;

    imshow("output",output2);
    waitKey(0);
	return 0;
}