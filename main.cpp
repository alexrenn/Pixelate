#include <iostream>
#include <opencv2/opencv.hpp>
#include "MakeImage.hpp"
#include "Pixelate.cpp"
  using namespace cv;

int main() {
    //Read the image from path
    std::string PATH = "/Users/alexren/Downloads/blond.jpg";
    Mat image = imread(PATH, IMREAD_COLOR);
    
    //test to see if image can be read
    if (image.empty()) {
        std::cerr << "Could not read the image: " << PATH << std::endl;
        return 1;
    }

    //test to see if pixel values can be accessed
    try {
        int x = image.at<Vec3b>(10, 29)[0];
    } catch (const cv::Exception& e) {
        std::cerr << "Error accessing pixel value: " << e.what() << std::endl;
        return 1;
    }


   char qpixelart, size;
   enum Imagesize plateSize;
   int blur;
   
  //ask if using program to create lego pixel art
   std::cout << "Are you using a baseplate to create pixel art? Answer 'y' or 'n'" << std::endl;
   std::cin >> qpixelart;
   //if yes, ask what size
   if(qpixelart == 'y')
   {
      do{
          std::cout << "What size baseplate do you have? /n Type 's' for 48x48, 'm' for 72x72, and 'l' for 100x100" << std::endl;
          std::cin >> size;
        }while(size != 's' && size != 'm' && size != 'l');

      if(size == 's') 
        plateSize = SMALL;
      else if (size == 'm') 
        plateSize = MEDIUM;
      else if (size == 'l') 
        plateSize = LARGE;
      
      Pixelate downloadedImage(image, plateSize);
      std::cout << "Image width: " << downloadedImage.getWidth() << std::endl;
      std::cout << "Image height: " << downloadedImage.getHeight() << std::endl;
    
      // Display the image
      cv::imshow("Pixel by Pixel Image", downloadedImage.pixelateImage());
      cv::waitKey(0);

      // Save the image to a file
      cv::imwrite("output_image.png", downloadedImage.pixelateImage());
   }else if (qpixelart = 'n')
   {
       std::cout << "On a scale of 0-100, how much would you like to blur your image?" << std::endl;
       std::cin >> blur;

       Pixelate downloadedImage(image, blur);
       std::cout << "Image width: " << downloadedImage.getWidth() << std::endl;
      std::cout << "Image height: " << downloadedImage.getHeight() << std::endl;
    
      // Display the image
      cv::imshow("Pixel by Pixel Image", downloadedImage.pixelateImage());
      cv::waitKey(0);

      // Save the image to a file
      cv::imwrite("output_image.png", downloadedImage.pixelateImage());
   }


    return 0;

}
