#ifndef PIXELATE_HPP
#define PIXELATE_HPP
#include "ColorMatch.hpp"
#include "LegoColorClass.hpp"
#include "MakeImage.hpp"
#include <opencv2/opencv.hpp>

enum Imagesize{
    SMALL = 2304, MEDIUM = 5184, LARGE = 10000
};

class Pixelate {
private:
  enum Imagesize plateSize;
  cv::Mat image;
  int blurIndex;
public:
  Pixelate(cv::Mat img, int blur);
  Pixelate(cv::Mat img, Imagesize size);
  int DetermineBlur();
  cv::Vec3b averageValue(int offsetx, int offsety, int blocksize);
  cv::Mat pixelateImage();
  int getWidth();
  int getHeight();
};

#endif // PIXELATE_HPP
