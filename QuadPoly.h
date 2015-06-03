#pragma once
#include "Strategy.h"
class QuadPoly :
	public Strategy
{
public:
	QuadPoly(Mat InputImage);
	virtual ~QuadPoly();
	virtual void detectSkin();

private:
	void getNormalized(Mat &Normalized, Mat &Sum);
	void getMask(const Mat &Normalized);
};

