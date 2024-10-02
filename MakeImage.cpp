/*
This class creates the image using the average values calculated in Pixelate.cpp.
It iterates through each pixel and sets the pixel color.
*/
#include "MakeImage.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

MakeImage::MakeImage(int x, int y){
    width = x;
    height = y;
 }


cv::Mat MakeImage::makePixels(int offsetx, int offsety,int blocksize, cv::Vec3b color, cv::Mat output)
{
    double colB = color[0];
    double colG = color[1];
    double colR = color[2];

    // Iterate through each pixel and set its color
    for (int x = offsetx; x < offsetx+blocksize; x++) {
        for (int y = offsety; y < offsety+blocksize; y++) {
            output.at<cv::Vec3b>(x, y) = cv::Vec3b(colB, colG, colR );
        }
    }
    return output;
}
