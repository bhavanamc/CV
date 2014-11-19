#include "opencv2\opencv.hpp"
#include <stdio.h>
#include <opencv2/legacy/legacy.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdarg.h>
#include <fstream>
#include <math.h>
#include <windows.h>
#include <string.h>

 
using namespace std;
using namespace cv;

//main.cpp starts here
int main(char *argv, int argc){

	//Some useful variables
	Mat Img, segImg, segImgRGB;
	double SpatialRad,ColorRad;
	int MaxLevel=1;

	//Reading input file
	char *filename= argv[1];
	Img= cvLoadImage(filename,CV_32SC3);
	
	//Converting from RGB to CIE LAB space
	cvtColor(Img, Img, CV_BGR2Lab);

	//Setting mean shift parameters
	SpatialRad=20;ColorRad=30;

	pyrMeanShiftFiltering(Img,segImg,SpatialRad,ColorRad,MaxLevel);
	
	//Converting image back to RGB format from CIE LAB
	cvtColor(segImg,segImg,CV_Lab2BGR);

	imshow("Segmented image",segImg);
	waitKey(0);

}
