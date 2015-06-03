#include "stdafx.h"
#include "EllipseModel.h"


EllipseModel::EllipseModel(Mat inputImg)
	:Strategy(inputImg)
{
	setSkinCrCbHist();
}


EllipseModel::~EllipseModel()
{
}

void EllipseModel::setSkinCrCbHist()
{
	skinCrCbHist = Mat::zeros(Size(256, 256), CV_8UC1);
	ellipse(skinCrCbHist, Point(113, 155.6), Size(23.4, 15.2), 
		43.0, 0.0, 360.0, Scalar(255, 255, 255), -1);
}

void EllipseModel::detectSkin()
{
	Mat faceYCrCb;
	cvtColor(SrcImage, faceYCrCb, CV_BGR2YCrCb);

	DstImage.create(SrcImage.size(), CV_8UC1);
	DstImage.setTo(0);

	MatIterator_<uchar> skinMaskIter = DstImage.begin<uchar>();
	MatIterator_<uchar> skinMaskIterEnd = DstImage.end<uchar>();

	MatIterator_<Vec3b> faceYCrCbIter = faceYCrCb.begin<Vec3b>();
	MatIterator_<Vec3b> faceYCrCbIterEnd = faceYCrCb.end<Vec3b>();

	for (; skinMaskIter != skinMaskIterEnd&&faceYCrCbIter != faceYCrCbIterEnd;
		skinMaskIter++, faceYCrCbIter++)
	{
		int crChannelVal = (*faceYCrCbIter)[1];
		int cbChannelVal = (*faceYCrCbIter)[2];
		if (skinCrCbHist.at<uchar>(crChannelVal, cbChannelVal) > 0)
		{
			*skinMaskIter = 255;
		}
	}
}