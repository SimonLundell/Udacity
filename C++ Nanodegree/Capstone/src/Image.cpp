#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>

#include "Image.h"

// Default constructor
Image::Image() {
  std::cout << "Default constructor\n";
  _image = cv::imread("/home/simon/Udacity/C++ Nanodegree/Capstone/images/3.jpg", cv::IMREAD_COLOR);
    if (_image.empty()) {
    std::cerr << "Image failed to read\n";
    return;
    }
  _imagePath = "/home/simon/Udacity/C++ Nanodegree/Capstone/images/bbox-example-image.jpg";
  _width = _image.cols;
  _height = _image.rows;
  _channels = _image.channels();
  std::cout << "Image read, width: " << _width << " height: " << _height << " and channels: " << _channels << "at " << this 
  << std::endl;
}

// Constructor
Image::Image(const std::string filename) {
  _image = cv::imread(filename, cv::IMREAD_COLOR);
  if (_image.empty()) {
    std::cerr << "Image failed to read\n";
    return;
  }
  resize(_image, _image, cv::Size(640,480));
  _imagePath = filename;
  _width = _image.cols;
  _height = _image.rows;
  _channels = _image.channels();
  std::cout << "Image read, width: " << _width << " height: " << _height << " and channels: " << _channels << "at " << this 
  << std::endl;
}

// Copy constructor
Image::Image(const Image &source) {
  this->_image = source._image;
  this->_width = source._width;
  this->_height = source._height;
  this->_channels = source._channels;
  std::cout << "Image copied at " << this << std::endl;
}
// Copy with new color
Image::Image(const Image &source, cv::ImreadModes colorScheme) {
  _image = cv::imread(source._imagePath, colorScheme);
  if (this->_image.empty()) {
    std::cerr << "Failed to copy image with new color-scheme\n";
    return;
  }
  this->_width = source._width;
  this->_height = source._height;
  this->_channels = this->_image.channels();
  std::cout << "Image copied with new color-scheme at " << this << std::endl;
}

Image::~Image() {
  std::cout << "Destructor called " << this << std::endl;
}

// Basic functions
void Image::showRawImg() {   
  const std::string named_Window("Curved road");
  cv::namedWindow(named_Window);
  cv::imshow(named_Window, _image);
  cv::waitKey(0);
}