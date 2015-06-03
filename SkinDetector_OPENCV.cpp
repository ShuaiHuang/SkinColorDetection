#include "stdafx.h"
#include "SkinDetector_OPENCV.h"


SkinDetector_OPENCV::SkinDetector_OPENCV(Mat InputImg)
	:Strategy(InputImg)
{
}


SkinDetector_OPENCV::~SkinDetector_OPENCV()
{
}

void SkinDetector_OPENCV::detectSkin()
{
	CvAdaptiveSkinDetector SkinDetector(1, CvAdaptiveSkinDetector::MORPHING_METHOD_NONE);
	IplImage *SrcImgPtr = &SrcImage.operator IplImage();
	IplImage *DstImgPtr = &DstImage.operator IplImage();
	SkinDetector.process(SrcImgPtr, DstImgPtr);
}