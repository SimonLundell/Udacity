#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>

#include "Image.h"

// Constructor
Image::Image(const std::string filename) {
  _image = cv::imread(filename, cv::IMREAD_COLOR);
  if (_image.empty()) {
    std::cerr << "Image failed to read\n";
    return;
  }
  _imagePath = filename;
  _width = _image.cols;
  _height = _image.rows;
  _channels = _image.channels();
  std::cout << "Image read, width: " << _width << " height: " << _height << " and channels: " << _channels << std::endl;
}

// Copy constructor
Image::Image(const Image &source) {
  this->_image = source._image;
  this->_width = source._width;
  this->_height = source._height;
  this->_channels = source._channels;
  std::cout << "Image copied\n";
}
// Copy with new color
Image::Image(const Image &source, cv::ImreadModes colorScheme) {
  this->_image = cv::imread(source._imagePath, colorScheme);
  if (this->_image.empty()) {
    std::cerr << "Failed to copy image with new color-scheme\n";
    return;
  }
  this->_width = source._width;
  this->_height = source._height;
  this->_channels = this->_image.channels();
  std::cout << "Image copied with new color-scheme\n";
}

Image::~Image() {
  std::cout << "Destructor called \n";
}

// Basic functions
void Image::showRawImg() {   
  const std::string named_Window("Curved road");
  cv::namedWindow(named_Window);
  cv::imshow(named_Window, _image);
  cv::waitKey(0);
}