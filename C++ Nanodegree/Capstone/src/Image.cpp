#include "Image.h"
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

// Constructor
Image::Image() : _imagePath("/home/simon/Udacity/C++ Nanodegree/Capstone/images/curved_lane.jpg") {
  _image = cv::imread(_imagePath, cv::IMREAD_COLOR);
  width = _image.cols;
  height = _image.rows;
}

// Basic functions
void Image::showImg() {   
  const std::string named_Window("Curved road");
  cv::namedWindow(named_Window);
  cv::imshow(named_Window, _image);
  cv::waitKey(0);
}