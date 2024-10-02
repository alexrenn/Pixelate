#include "ColorMatch.hpp"
#include <cmath>
#include <opencv2/opencv.hpp>


double ColorMatch::colorDistance(const cv::Vec3b& color1, const cv::Vec3b& color2){
    double distanceb;
    double distancer;
    double distanceg;
    double distance;

    //convert bgr int values to type double
    distanceb = static_cast<double>(color1[0]) - static_cast<double>(color2[0]);
    distancer = static_cast<double>(color1[1]) - static_cast<double>(color2[1]);
    distanceg = static_cast<double>(color1[2]) - static_cast<double>(color2[2]);

    //calcuate Euclidean distance and return;
    distance = std::sqrt(distanceb*distanceb+distancer*distancer+distanceg*distanceg);
    return distance;
}

LegoColorClass::LegoColor ColorMatch::findClosestLegoColor(const cv::Vec3b& pixelBRG, std::vector<LegoColorClass::LegoColor> legoColors)
{
    //initalize closest color to the first color in list
    LegoColorClass::LegoColor closestColor;
    double minDistance = colorDistance(pixelBRG,legoColors[0].bgr);

    //O(n) complexity
    //loop through all legoColors
    for(const auto& legoColor: legoColors)
    {
        double distance = colorDistance(pixelBRG, legoColor.bgr);
        if(distance < minDistance)
        {
            minDistance = distance;
            closestColor = legoColor;
        }
    }

    return closestColor;
}