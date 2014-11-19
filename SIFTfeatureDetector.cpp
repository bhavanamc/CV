#include "opencv2\opencv.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\nonfree\features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <cstdio>
#include <iostream>

using namespace std;
using namespace cv;


int main( char* argv, int argc )
{	
	//Some useful varibles
	char* filename;
	Mat OrigImg,GrayImg;

	//Reading input file
     filename = argv[1];
    OrigImg = cvLoadImage(filename, 0);

	OrigImg.convertTo(OrigImg,CV_8U,1.0,0.0);

	imshow("Original img",OrigImg);
	waitKey(0);

	//Keypoints
	Vector<KeyPoint>Keypoints1;
	Mat descriptors1; //descriptors1.create(OrigImg.rows,OrigImg.cols,CV_8U);

	Mat mask; mask.create(OrigImg.rows,OrigImg.cols,CV_8U);

	cv::SiftFeatureDetector detector;
    std::vector<cv::KeyPoint> keypoints;
    detector.detect(OrigImg, keypoints);
	
	cv::Mat output;
    cv::drawKeypoints(OrigImg, keypoints, output);
    cv::imwrite("sift_result.jpg", output);


   
	
    return 0;
}