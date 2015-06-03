#include "stdafx.h"
#include "YCbCrColorSpace.h"


YCbCrColorSpace::YCbCrColorSpace(Mat Input)
	:Strategy(Input)
{
}


YCbCrColorSpace::~YCbCrColorSpace()
{
}

void YCbCrColorSpace::detectSkin()
{
	cvtColor(SrcImage, SrcImage, CV_BGR2YCrCb);
	MatIterator_<Vec3b> Iter2Src = SrcImage.begin<Vec3b>();
	MatIterator_<Vec3b> Iter2SrcEnd = SrcImage.end<Vec3b>();
	MatIterator_<uchar> Iter2Dst = DstImage.begin<uchar>();

	for (; Iter2Src != Iter2SrcEnd; Iter2Src++, Iter2Dst++){
		(*Iter2Dst) = 0;
		if ((*Iter2Src)[2] > 77 && (*Iter2Src)[2] < 127){
			if ((*Iter2Src)[1]>133 && (*Iter2Src)[1] < 173){
				(*Iter2Dst) = 255;
			}
		}
	}
}