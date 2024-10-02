/*
This class matches the average pixel color to the closest lego color. */
#ifndef COLORMATCH_HPP
#define COLORMATCH_HPP
#include "LegoColorClass.hpp"
#include <cmath>
#include <opencv2/opencv.hpp>

class ColorMatch {
    public:
    //this function calculates the distance between the current bgr value and lego color
        double colorDistance(const cv::Vec3b& color1, const cv::Vec3b& color2);
    //this function loops through all the lego colors per block and selects the minimum distance
    //should be able to be optimized (run in parallel maybe?)
        LegoColorClass::LegoColor findClosestLegoColor(const cv::Vec3b& pixelBRG, std::vector<LegoColorClass::LegoColor> legoColors);
};
#endif //COLORMATCH_HPP
