#include "Pixelate.hpp"
#include "MakeImage.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

//takes in image as parameter
Pixelate::Pixelate(cv::Mat img, int blur){
  image = img;
  blurIndex = blur;
}

int Pixelate::imgWidth()
{
  return image.rows;
}

int Pixelate::imgHeight()
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
   std::cout << "Block (" << offsetx << ", " << offsety << ") - Avg Values: ["  << avgX << ", " << avgY << ", " << avgZ << "]" << std::endl;


  std::vector<double> averageXYZ = { avgX, avgY, avgZ };

  return averageXYZ;
}

cv::Mat Pixelate::pixelateImage()
{
  // Create an empty image with 3 channels (BGR) and 8-bit depth
  cv::Mat output(this -> imgHeight(), this -> imgWidth(), CV_8UC3, cv::Scalar(0, 0, 0));
  MakeImage pixelatedImage(imgWidth(), imgHeight());

  int blocksize = ((imgHeight()+imgWidth())/2)/blurIndex;
  
  for(int i = 0; i <= imgWidth() - blocksize; i += blocksize)
  {
      for(int j = 0; j <= imgHeight()- blocksize; j += blocksize)
    {
        pixelatedImage.makePixels(i, j, blocksize, averageValue(i, j, blocksize), output);
    }
  }

  return output;
}