/*
Colors based on this list here: https://www.jennyscrayoncollection.com/2021/06/all-current-lego-colors.html
Credit: Jenny Crowther
*/
#ifndef LEGOCOLOR_HPP
#define LEGOCOLOR_HPP

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

class LegoColorClass {

public:
    struct LegoColor {
        std::string name;
        cv::Vec3b bgr; // OpenCV uses BRG by default
        

        //copy constructor?
    };
    std::vector<LegoColorClass::LegoColor> getLegoColors();

private:
    std::vector<LegoColor> legoColors = {
         { "Black",    cv::Vec3b(21, 21, 21) },
         { "White",    cv::Vec3b(244, 244, 244) },
        // { "Red",      cv::Vec3b(0, 0, 181) },      // Note: OpenCV uses BGR
        // { "Blue",     cv::Vec3b(184, 87, 0) },
        // { "Yellow",   cv::Vec3b(0, 204, 255) },
        // // Add more LEGO colors as needed
        // { "Green",    cv::Vec3b(0, 128, 0) },
        // { "Dark Gray",cv::Vec3b(92, 110, 109) },
        //  { "Light Gray",cv::Vec3b(211, 211, 211) },
        // { "Brown",    cv::Vec3b(42, 42, 165) },
        // { "Orange",   cv::Vec3b(0, 165, 255) },
         { "Titanium Metallic", cv::Vec3b(62, 66, 66)},
         { "Light Royal Blue",   cv::Vec3b(247, 212, 180)},
         { "Dark Orange",   cv::Vec3b(34, 83, 166)},
         { "Medium Blue",   cv::Vec3b(219, 147, 90)},
         { "Aqua",   cv::Vec3b(209, 215, 179)},
         { "Sand Green",   cv::Vec3b(172, 188, 160)},
         { "Medium Nougat", cv::Vec3b(85,125,170)},
         { "Bright Red", cv::Vec3b(9, 26, 201)},
         { "Flame Yellowish Orange", cv::Vec3b(109,183,252)},
         { "Sand Yellow", cv::Vec3b(115,138,149)},
         { "Earth Green", cv::Vec3b(50,70,24)},
         { "Earth Blue", cv::Vec3b(99,52,10)},
         { "Bright Orange", cv::Vec3b(28,143,240)},
         { "Dark Stone Grey", cv::Vec3b(101, 103, 100)},
         { "Medium Stone Grey", cv::Vec3b(159, 161, 160)},
         { "Cool Silver", cv::Vec3b(121, 119, 119)},
         { "Medium Lavender", cv::Vec3b(180, 117, 150)},
         { "Lavender", cv::Vec3b(208, 166, 188)},
         { "Medium Lilac", cv::Vec3b(146, 47, 76)},
         { "Bright Violet", cv::Vec3b(181, 114, 118)},
         { "Bright Blue", cv::Vec3b(183, 108, 0)},
         { "Light Royal Blue", cv::Vec3b(234, 191, 120)},
         { "Sand Blue", cv::Vec3b(151, 130, 103)},
         { "Dark Azur", cv::Vec3b(218, 163, 0)},
         { "Medium Azur", cv::Vec3b(211, 190, 0)},
         { "Bright Bluish Green", cv::Vec3b(159, 158, 24)},
         { "Dark Green", cv::Vec3b(71, 146, 0)},
         { "Bright Green", cv::Vec3b(77, 175, 0)},
         { "Bright Yellowish Green", cv::Vec3b(60, 202, 154)},
         { "Spring Yellowish Green", cv::Vec3b(151, 225, 204)},
         { "Olive Green", cv::Vec3b(83, 131, 130)},
         { "Dark Green", cv::Vec3b(71, 146, 0)},
         { "Bright Yellow", cv::Vec3b(3, 205, 255)},
         { "Cool Yellow", cv::Vec3b(121, 245, 255)},
         { "Warm Gold", cv::Vec3b(55, 151, 195)},
         { "Warm Gold Drum Lacquered", cv::Vec3b(42, 161, 42)},
         { "Metalized Gold", cv::Vec3b(119, 192, 224)},
         { "Vibrant Coral", cv::Vec3b(98, 108, 249)},
         { "Bright Orange", cv::Vec3b(32, 125, 245)},
         { "Dark Brown", cv::Vec3b(13, 24, 59)},
         { "Reddish Brown", cv::Vec3b(20, 46, 105)},
         { "Nougat", cv::Vec3b(95, 139, 222)},
         { "Light Nougat", cv::Vec3b(158, 195, 252)},
         { "Brick Yellow", cv::Vec3b(142, 196, 142)},
         { "New Dark Red", cv::Vec3b(27, 19, 127)},
         { "Bright Red", cv::Vec3b(33, 26, 221)},
         { "Bright Reddish Violet", cv::Vec3b(125, 28, 181)},
         { "Bright Purple", cv::Vec3b(162, 93, 162)},
         { "Light Purple", cv::Vec3b(205, 173, 205)},

        // ... add other colors

        // 
        //   //initalize colors

//   BGRColor mediumnougat(33,49,67);
//   BGRColor brightred(4,10,79);
//   BGRColor flameyellowishorange(24,73,97);
//   BGRColor brickyellow(62,80,89);
//   BGRColor mediumlilac(57,21,25);
        // 
    };


};



// Function to initialize LEGO colors


#endif // LEGOCOLOR_HPP