#pragma once
class Strategy
{
public:
	Strategy(Mat FaceImg);
	virtual ~Strategy();
	virtual void detectSkin() = 0;
	void getResult(Mat &Result);

protected:
	Mat SrcImage, DstImage;
	void normalizeImage(Mat &Src);
};

