#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>

#include "Image.h"

// Constructor
Image::Image() : _imagePath("/home/simon/Udacity/C++ Nanodegree/Capstone/images/curved_lane.jpg") {
  _image = cv::imread(_imagePath, cv::IMREAD_COLOR);
  _width = _image.cols;
  _height = _image.rows;
  _channels = _image.channels();
}

Image::Image(const std::string filename) {
  _image = cv::imread(filename, cv::IMREAD_COLOR);
  if (_image.empty()) {
    std::cerr << "Image failed to read\n";
  }
  std::cout << "Image read\n";
  _width = _image.cols;
  _height = _image.rows;
  _channels = _image.channels();
}

// Basic functions
void Image::showRawImg() {   
  const std::string named_Window("Curved road");
  cv::namedWindow(named_Window);
  cv::imshow(named_Window, _image);
  cv::waitKey(0);
}