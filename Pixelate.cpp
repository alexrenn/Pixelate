#include "Pixelate.hpp"
#include "MakeImage.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

//takes in image as parameter
Pixelate::Pixelate(cv::Mat img, int blur){
  image = img;
  blurIndex = blur;
}

Pixelate::Pixelate(cv::Mat img, Imagesize size){
  image = img;
  plateSize = size;
  blurIndex = 0;
}

int Pixelate::getWidth()
{
  return image.rows;
}

int Pixelate::getHeight()
{
  return image.cols;
}

std::vector<double> Pixelate::averageValue(int offsetx, int offsety, int blocksize)
{
  int pixelcount = 0;
  int sumX = 0;
  int sumY = 0;
  int sumZ = 0;
  for(int i = offsetx; i < offsetx + blocksize; i++)
  {
    for(int j = offsety; j < offsety + blocksize; j++)
	  {
      sumX += image.at<Vec3b>(i,j) [0];
      sumY += image.at<Vec3b>(i,j) [1];
	    sumZ += image.at<Vec3b>(i,j) [2]; 
      pixelcount++;
    }
  }

  double avgX = sumX/pixelcount;
  double avgY = sumY/pixelcount;
  double avgZ = sumZ/pixelcount;
  //std::cout << "Block (" << offsetx << ", " << offsety << ") - Avg Values: ["  << avgX << ", " << avgY << ", " << avgZ << "]" << std::endl;
  std::vector<double> averageXYZ = { avgX, avgY, avgZ };

  return averageXYZ;
}


//min blocksize depending on size of plate
int Pixelate::DetermineBlur()
{   
    int totalImagePixels = getWidth() * getHeight();
    int input = 0;
    
    if(this -> plateSize == SMALL)
    {
        do{
            std::cout << "Enter blur intensity > 0 (blocksize). If reprompted, enter a larger number." << std::endl;
            std::cin >> input;
        }
        while(totalImagePixels/(input*input) > SMALL);
    }
    
    if(this -> plateSize == MEDIUM)
    {
        do{
            std::cout << "Enter blur intensity > 0 (blocksize). If reprompted, enter a larger number." << std::endl;
            std::cin >> input;
        }
        while(totalImagePixels/(input*input) > MEDIUM);
    }

    if(this -> plateSize == LARGE)
    {
        do{
            std::cout << "Enter blur intensity > 0 (blocksize). If reprompted, enter a larger number." << std::endl;
            std::cin >> input;
        }
        while(totalImagePixels/(input*input) > LARGE);
    }

    return input;
}

cv::Mat Pixelate::pixelateImage()
{
  int numBlocks = 0;
  int blocksize = 0;
  // Create an empty image with 3 channels (BGR) and 8-bit depth
  cv::Mat output(this -> getHeight(), this -> getWidth(), CV_8UC3, cv::Scalar(0, 0, 0));
  MakeImage pixelatedImage(getWidth(), getHeight());

  //determine blocksize based on if lego constraints are present
  if(this -> blurIndex != 0)
    blocksize = this -> blurIndex;
  else
     blocksize =  DetermineBlur();

  std::cout << "blocksize: " << blocksize << std::endl;
  
  for(int i = 0; i <= getWidth() - blocksize; i += blocksize)
  {
      for(int j = 0; j <= getHeight() - blocksize; j += blocksize)
    {
        numBlocks++;
        pixelatedImage.makePixels(i, j, blocksize, averageValue(i, j, blocksize), output);
    }
  }
    std::cout << "Number of Pieces: " << numBlocks << std::endl;

  return output;
}