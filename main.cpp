 #include <iostream>
#include <opencv2/opencv.hpp>
#include "MakeImage.hpp"
#include "Pixelate.cpp"
  using namespace cv;

int main() {
    //Read the image from path
    std::string PATH = "/Users/alexren/Downloads/SZA_SOS.jpeg";
    Mat image = imread(PATH, IMREAD_COLOR);
    
    
    if (image.empty()) {
        std::cerr << "Could not read the image: " << PATH << std::endl;
        return 1;
    }

    try {
        int x = image.at<Vec3b>(10, 29)[0];
        std::cout << "Pixel value: " << x << std::endl;
    } catch (const cv::Exception& e) {
        std::cerr << "Error accessing pixel value: " << e.what() << std::endl;
        return 1;
    }



    Pixelate sza(image, 30);
    std::cout << "Image width: " << sza.imgWidth() << std::endl;
    std::cout << "Image height: " << sza.imgHeight() << std::endl;



    // Display the image
    cv::imshow("Pixel by Pixel Image", sza.pixelateImage());
    cv::waitKey(0);

    // Save the image to a file
    cv::imwrite("output_image.png", sza.pixelateImage());
    return 0;

}
