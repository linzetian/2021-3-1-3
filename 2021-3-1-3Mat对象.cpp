//Mat对象
#include<opencv2/opencv.hpp>
#include<opencv2\imgproc\types_c.h>//CV_BGR2GRAY的头文件
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src, dst;
	src = imread("F:/image/1.2.png");
	if (!src.data)
	{
		printf("can not load the picture\n");
		return -1;
	}
	namedWindow("input",WINDOW_AUTOSIZE);
	imshow("input",src);
	//dst = Mat(src.size(), src.type());//初始化像素大小，类型一样
	//dst = Scalar(0, 0, 0);//初始化背景
	//dst = src.clone();//克隆等价于src.copyTo(dst)
	printf("input image channels:%d\n",src.channels());
	cvtColor(src,dst,CV_BGR2GRAY);//灰度转化
	int cols = dst.cols;
	int rows = dst.rows;
	printf("output image channels:%d\n", dst.channels());
	printf("rows:%d\ncols:%d\n", rows, cols);
	const uchar* firstrow = dst.ptr<uchar>(0,10);
	printf("first pixel vaule:%d\n",*firstrow);
	Mat M(100, 100, CV_8UC3, Scalar(0, 0, 255));
	Mat m2 = Mat::zeros(2, 2, CV_8UC1);
	cout << "m2" << endl << m2<<endl;
	Mat m3 = Mat::eye(2, 2, CV_8UC1);
	cout << "m3" << endl << m3 << endl;
	//cout << "M" << endl << M;
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output",M);
	waitKey();
	return 0;
}