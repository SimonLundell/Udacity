#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>

#include "Image.h"

// Default constructor
Image::Image() {
  _image = cv::Mat::zeros(cv::Size(640,480), CV_8UC3);
    if (_image.empty()) {
    std::cerr << "Failed to create black image " << this << std::endl;
    return;
    }
  _imagePath = {};
  _width = _image.cols;
  _height = _image.rows;
  _channels = _image.channels();
  std::cout << "Default image. Width: " << _width << ", height: " << _height << " and channels: " << _channels << " at " << this 
  << std::endl;
}

// Constructor
Image::Image(const std::string filename) {
  _image = cv::imread(filename, cv::IMREAD_COLOR);
  if (_image.empty()) {
    std::cerr << "Image failed to read at " << this << std::endl;
    return;
  }
  cv::resize(_image, _image, cv::Size(640,480));
  _imagePath = filename;
  _width = _image.cols;
  _height = _image.rows;
  _channels = _image.channels();
  std::cout << "Image read. Width: " << _width << ", height: " << _height << " and channels: " << _channels << " at " << this 
  << std::endl;
}

// Copy constructor
Image::Image(const Image &source) {
  this->_image = source._image.clone();
  this->_imagePath = source._imagePath;
  this->_width = source._width;
  this->_height = source._height;
  this->_channels = source._channels;
  std::cout << "Image " << source._imagePath << " copied from " << &source << " to " << this << std::endl;
}

// Assignment operator
Image &Image::operator=(const Image &source) {
  std::cout << "Assigning content at " << &source << " to " << this << std::endl;
  if (this == &source) {
    return *this;
    }
  this->_image.release();

  this->_image = source._image.clone();
  this->_width = source._width;
  this->_height = source._height;
  this->_channels = source._channels;
  
  return *this;
}

// Move constructor
Image::Image(Image &&source) {
  std::cout << "Moving from " << &source << " to " << this << std::endl;
  cv::swap(source._image, this->_image);
  cv::swap(source._width, this->_width);
  cv::swap(source._height, this->_height);
  cv::swap(source._channels, this->_channels);
}

// Move assignment operator
Image &Image::operator=(Image &&source) {
  std::cout << "Moving and assigning " << &source << " to " << this << std::endl;
  if (this == &source) {
    return *this;
  }

  cv::swap(source._image, this->_image);
  cv::swap(source._width, this->_width);
  cv::swap(source._height, this->_height);
  cv::swap(source._channels, this->_channels);

  return *this;
}

// Destructor
Image::~Image() {
  if (!_image.empty()) {
    _image.release();
  }
  std::cout << "Destroying image " << this->_imagePath  << " at address " << this << std::endl;
}