/*
This class takes in an image as a parameter, calculates pixelates the image
based on the blur intensity.
*/

#include <omp.h>
#include "Pixelate.hpp"
#include "MakeImage.hpp"
#include "ColorMatch.hpp"
#include "LegoColorClass.hpp"
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

//this function calculates the blurred pixel's bgr value and returns it in a vector
cv::Vec3b Pixelate::averageValue(int offsetx, int offsety, int blocksize)
{
  int pixelcount = 0;
  int sumB = 0;
  int sumR = 0;
  int sumG = 0;
  
  //collapse for loops. Shared variable sumB, sumR, sumG, and pixelCount. Ensure threads wait to for other threads to complete before updating
 
 // #pragma omp parallel for collapse (2) reduction (+:sumB, sumR, sumG, pixelcount)
  for(int i = offsetx; i < offsetx + blocksize; i++)
  {
    for(int j = offsety; j < offsety + blocksize; j++)
	  {
      sumB += image.at<Vec3b>(i,j) [0];
      sumR += image.at<Vec3b>(i,j) [1];
	    sumG += image.at<Vec3b>(i,j) [2]; 
      pixelcount++;
    }
  }

//don't move on until all threads are complete
//#pragma omp barrier
  double avgB = sumB/pixelcount;
  double avgR = sumR/pixelcount;
  double avgG = sumG/pixelcount;
  std::cout << "Block (" << offsetx << ", " << offsety << ") - Avg Values: ["  << avgB << ", " << avgR << ", " << avgG << "]" << std::endl;
  cv::Vec3b averageBRG;
  averageBRG[0] = avgB;
  averageBRG[1] = avgR;
  averageBRG[2] = avgG;

  return averageBRG;
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
  // Create an empty image named output with 3 channels (BGR) and 8-bit depth
  cv::Mat output(this -> getHeight(), this -> getWidth(), CV_8UC3, cv::Scalar(0, 0, 0));
  MakeImage pixelatedImage(getWidth(), getHeight());

  //determine blocksize based on if lego constraints are present
  if(this -> blurIndex != 0)
    blocksize = this -> blurIndex;
  else
     blocksize =  DetermineBlur();

  std::cout << "blocksize: " << blocksize << std::endl;
  
  //iternate through each block, match the bgr to closest lego color
  //call MakeImage's function makePixels 

  ColorMatch distanceFinder;
  cv::Vec3b averagePixelValue;
  LegoColorClass getColors;
  cv::Vec3b averageBRG;
  
  for(int i = 0; i <= getWidth() - blocksize; i += blocksize)
  {
    for(int j = 0; j <= getHeight() - blocksize; j += blocksize)
    {
      numBlocks++;
      averageBRG = averageValue(i,j,blocksize);
      //std::cout << "averageBRG[0]: " << averageBRG[0] << std::endl;
      std::cout << (distanceFinder.findClosestLegoColor((averageBRG), getColors.getLegoColors())).bgr << std::endl;
      pixelatedImage.makePixels(i, j, blocksize, (distanceFinder.findClosestLegoColor((averageBRG), getColors.getLegoColors())).bgr, output);
    }
  }
    std::cout << "Number of Pieces: " << numBlocks << std::endl;

  return output;
}