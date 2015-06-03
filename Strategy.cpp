#include "stdafx.h"
#include "Strategy.h"


Strategy::Strategy(Mat InputImg)
{
	SrcImage = InputImg.clone();
	DstImage.create(SrcImage.size(),CV_8UC1);
	CV_Assert(!SrcImage.empty() && SrcImage.channels() == 3);
	//normalizeImage(SrcImage);
}

Strategy::~Strategy()
{
}

void Strategy::getResult(Mat &Result)
{
	Result = DstImage.clone();
}

void Strategy::normalizeImage(Mat &Src)
{
	cvtColor(Src, Src, CV_BGR2HSV);
	vector<Mat> ChanVec;
	split(Src, ChanVec);
	equalizeHist(ChanVec[2], ChanVec[2]);
	merge(ChanVec, Src);
	cvtColor(Src, Src, CV_HSV2BGR);
}