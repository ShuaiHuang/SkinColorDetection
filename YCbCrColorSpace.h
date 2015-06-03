#pragma once
#include "Strategy.h"
class YCbCrColorSpace :
	public Strategy
{
public:
	YCbCrColorSpace(Mat Input);
	virtual ~YCbCrColorSpace();
	virtual void detectSkin();
};

