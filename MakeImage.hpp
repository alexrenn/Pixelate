#ifndef MAKEIMAGE_HPP
#define MAKEIMAGE_HPP
#include <opencv2/opencv.hpp>
 
class MakeImage {
private:
    int width;
    int height;

public:
    MakeImage(int x, int y);
    cv::Mat makePixels(int offsetx, int offsety,int blocksize, cv::Vec3b color,cv::Mat output );
};

#endif // MAKEIMAGE_H