#include "stdafx.h"
#include "RGBColorSpace.h"


RGBColorSpace::RGBColorSpace(Mat Input)
	:Strategy(Input)
{
}


RGBColorSpace::~RGBColorSpace()
{
}

void RGBColorSpace::detectSkin()
{
	MatIterator_<Vec3b> Iter2Src = SrcImage.begin<Vec3b>();
	MatIterator_<Vec3b> Iter2SrcEnd = SrcImage.end<Vec3b>();
	MatIterator_<uchar> Iter2Dst = DstImage.begin<uchar>();

	for (; Iter2Src != Iter2SrcEnd; Iter2Src++, Iter2Dst++){
		(*Iter2Dst) = 0;
		if ((*Iter2Src)[2] > 95 && (*Iter2Src)[1] > 40 && (*Iter2Src)[0] > 20
			&& (*Iter2Src)[2] > (*Iter2Src)[0] && (*Iter2Src)[2] > (*Iter2Src)[1]
			&& abs((*Iter2Src)[2] - (*Iter2Src)[1]) > 15){
			uchar Max, Min;
			if ((*Iter2Src)[0] >= (*Iter2Src)[1]){
				Max = (*Iter2Src)[0];
				Min = (*Iter2Src)[1];
			}
			else{
				Max = (*Iter2Src)[1];
				Min = (*Iter2Src)[0];
			}
			if ((*Iter2Src)[2] > Max){
				Max = (*Iter2Src)[2];
			}
			else if ((*Iter2Src)[2] < Min){
				Min = (*Iter2Src)[2];
			}

			if (Max - Min > 15){
				(*Iter2Dst) = 255;
			}
		}
	}
}