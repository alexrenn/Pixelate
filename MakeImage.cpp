#include "MakeImage.hpp"
#include <opencv2/opencv.hpp>
  using namespace cv;

MakeImage::MakeImage(int x, int y){
    width = x;
    height = y;
 }


cv::Mat MakeImage::makePixels(int offsetx, int offsety,int blocksize, std::vector<double> avgValues, cv::Mat output)
{
    double avgX = avgValues.at(0);
    double avgY = avgValues.at(1);
    double avgZ = avgValues.at(2);

    // Iterate through each pixel and set its color
    for (int x = offsetx; x < offsetx+blocksize; x++) {
        for (int y = offsety; y < offsety+blocksize; y++) {
            // Set blue channel to x value, green channel to y value, and red channel to 128
            output.at<cv::Vec3b>(x, y) = cv::Vec3b(avgX, avgY, avgZ );

        }
    }
    return output;
}
