// SkinColor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Mat SrcImg = imread("G:/data/20150528173901.jpg");
	resize(SrcImg, SrcImg, Size(384, 512));
	Mat DstImg;

	//Strategy *Ptr2SkinDetector = new QuadPoly(SrcImg);
	//Strategy *Ptr2SkinDetector = new RGBColorSpace(SrcImg);
	//Strategy *Ptr2SkinDetector = new YCbCrColorSpace(SrcImg);
	//Strategy *Ptr2SkinDetector = new SkinDetector_OPENCV(SrcImg);
	Strategy *Ptr2SkinDetector = new EllipseModel(SrcImg);
	Ptr2SkinDetector->detectSkin();
	Ptr2SkinDetector->getResult(DstImg);
	//imwrite("G:/data/SkinColor.jpg", DstImg);
	namedWindow("Src");
	namedWindow("Dst");
	imshow("Src", SrcImg);
	imshow("Dst", DstImg);
	cvWaitKey(0);
	return 0;
}

