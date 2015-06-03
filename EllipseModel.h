#pragma once
#include "Strategy.h"
class EllipseModel :
	public Strategy
{
public:
	EllipseModel(Mat inputImg);
	virtual ~EllipseModel();
	virtual void detectSkin();

private:
	Mat skinCrCbHist;
	void setSkinCrCbHist();
};

