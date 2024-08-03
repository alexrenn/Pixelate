#ifndef PIXELATE_HPP
#define PIXELATE_HPP
#include <opencv2/opencv.hpp>

class Pixelate {
private:
  cv::Mat image;
  int blurIndex;
public:
  Pixelate(cv::Mat img, int blur);
  std::vector<double> averageValue(int offsetx, int offsety, int blocksize);
  cv::Mat pixelateImage();
  int imgWidth();
  int imgHeight();
};

#endif // PIXELATE_HPP
