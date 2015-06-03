# Skin Color Detection

## System Requirement

- Visual Studio Community 2013
- OpenCV 2.4.10

## Introduction

This repository is used for detection skin color in the image. Different methods are incorporated into this repository to detect skin in different circumstance.
Strategy pattern are used in this repository, so different method can be invoked simply by initial corresponding class name.

## Demo

```
Mat SrcImg = imread("G:/data/20150528173901.jpg");
resize(SrcImg, SrcImg, Size(384, 512));
Mat DstImg;

// Select different methods
//Strategy *Ptr2SkinDetector = new QuadPoly(SrcImg);
//Strategy *Ptr2SkinDetector = new RGBColorSpace(SrcImg);
//Strategy *Ptr2SkinDetector = new YCbCrColorSpace(SrcImg);
//Strategy *Ptr2SkinDetector = new SkinDetector_OPENCV(SrcImg);
Strategy *Ptr2SkinDetector = new EllipseModel(SrcImg);
Ptr2SkinDetector->detectSkin();
Ptr2SkinDetector->getResult(DstImg);
//imwrite("G:/data/SkinColor.jpg", DstImg);
namedWindow("Src");
namedWindow("Dst");
imshow("Src", SrcImg);
imshow("Dst", DstImg);
cvWaitKey(0);
return 0;
```

## Interfaces

### Base class - `Strategy`

The base class is an abstract class that converts the image to proper formation, so that the skin detection algorithm can process the images well.
```
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
```

- `Strategy(Mat FaceImg)` - construct the class with a image `FaceImg`
- `~Strategy()` - destructor
- `detectSkin()` - pure virtual function, used for detect skin color in derived class
- `getResult(Mat &Result)` - get the result image
- `normalizeImage(Mat &Src)` - normalize the image in the `V-channel`

### Skin Color Detector in OpenCV

```
class SkinDetector_OPENCV :
    public Strategy
{
public:
    SkinDetector_OPENCV(Mat InputImg);
    virtual ~SkinDetector_OPENCV();
    virtual void detectSkin();
};
```

### Quad Poly

```
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
```

### RGB Color Space

```
class RGBColorSpace :
    public Strategy
{
public:
    RGBColorSpace(Mat Input);
    virtual ~RGBColorSpace();
    virtual void detectSkin();
};
```

### YCbCr Color Space

```
class YCbCrColorSpace :
    public Strategy
{
public:
    YCbCrColorSpace(Mat Input);
    virtual ~YCbCrColorSpace();
    virtual void detectSkin();
};
```

### Ellipse model

```
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
```