#pragma once
#include "Strategy.h"
class SkinDetector_OPENCV :
	public Strategy
{
public:
	SkinDetector_OPENCV(Mat InputImg);
	virtual ~SkinDetector_OPENCV();
	virtual void detectSkin();
};

