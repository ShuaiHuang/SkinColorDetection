#include "stdafx.h"
#include "QuadPoly.h"


QuadPoly::QuadPoly(Mat InputImage)
	:Strategy(InputImage)
{
}


QuadPoly::~QuadPoly()
{
}

void QuadPoly::detectSkin()
{
	Mat NormImg(SrcImage.size(),CV_32FC3);
	Mat SumImg(SrcImage.size(), CV_16UC1);
	getMask(NormImg);
}

void QuadPoly::getNormalized(Mat &Normalized, Mat &Sum)
{
	MatIterator_<Vec3f> Iter2Nor = Normalized.begin<Vec3f>();
	MatIterator_<Vec3f> Iter2NorEnd = Normalized.end<Vec3f>();
	MatIterator_<Vec3b> Iter2Src = SrcImage.begin<Vec3b>();
	MatIterator_<Vec3b> Iter2SrcEnd = SrcImage.end<Vec3b>();
	MatIterator_<ushort> Iter2Sum = Sum.begin<ushort>();

	for (; Iter2Src != Iter2SrcEnd&& Iter2Nor != Iter2NorEnd; 
		Iter2Src++, Iter2Nor++, Iter2Sum++){
		ushort SumVal = (*Iter2Src)[0] + (*Iter2Src)[1] + (*Iter2Src)[2];
		(*Iter2Sum) = SumVal;
		(*Iter2Nor)[0] = (*Iter2Nor)[0] / SumVal;
		(*Iter2Nor)[1] = (*Iter2Nor)[1] / SumVal;
		(*Iter2Nor)[2] = (*Iter2Nor)[2] / SumVal;
	}
}

void QuadPoly::getMask(const Mat &Normalized)
{
	MatIterator_<Vec3b> Iter2Src = SrcImage.begin<Vec3b>();
	MatIterator_<Vec3b> Iter2SrcEnd = SrcImage.end<Vec3b>();
	MatIterator_<uchar> Iter2Dst = DstImage.begin<uchar>();

	for (; Iter2Src!=Iter2SrcEnd; Iter2Dst++, Iter2Src++){
		(*Iter2Dst) = 0;
		int SumVal = (*Iter2Src)[0] + (*Iter2Src)[1] + (*Iter2Src)[2];
		if ((*Iter2Src)[2] - (*Iter2Src)[1] >= 45){
			if ((*Iter2Src)[1] > (*Iter2Src)[0]){
				int T1 = 156 * (*Iter2Src)[2] - 52 * SumVal;
				int T2 = 156 * (*Iter2Src)[1] - 52 * SumVal;
				if (T1*T1 + T2*T2 >= (SumVal*SumVal >> 4)){
					T1 = 10000 * (*Iter2Src)[1] * SumVal;
					int Lower = -7760 * (*Iter2Src)[2] * (*Iter2Src)[2]
						+ 5601 * (*Iter2Src)[2] * SumVal
						+ 1766 * SumVal*SumVal;
					if (T1 > Lower){
						int Upper = -13767 * (*Iter2Src)[2] * (*Iter2Src)[2]
							+ 10743 * (*Iter2Src)[2] * SumVal
							+ 1452 * SumVal*SumVal;
						if (T1 < Upper){
							(*Iter2Dst) = 255;
						}
					}
				}
			}
		}
	}
}