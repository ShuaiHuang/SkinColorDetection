#pragma once
#include "Strategy.h"
class RGBColorSpace :
	public Strategy
{
public:
	RGBColorSpace(Mat Input);
	virtual ~RGBColorSpace();
	virtual void detectSkin();
};

