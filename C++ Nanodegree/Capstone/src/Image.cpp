#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>

#include "Image.h"

using namespace cv;

// Default constructor
Image::Image() {
  _image = Mat::zeros(Size(640,480), CV_8UC3);
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
  _image = imread(filename, IMREAD_COLOR);
  if (_image.empty()) {
    std::cerr << "Image failed to read at " << this << std::endl;
    return;
  }
  resize(_image, _image, Size(640,480));
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
  this->_imagePath = source._imagePath;
  this->_width = source._width;
  this->_height = source._height;
  this->_channels = source._channels;
  
  return *this;
}

// Move constructor
Image::Image(Image &&source) {
  std::cout << "Moving from " << &source << " to " << this << std::endl;
  swap(source._image, this->_image);
  swap(source._imagePath, this->_imagePath);
  swap(source._width, this->_width);
  swap(source._height, this->_height);
  swap(source._channels, this->_channels);
}

// Move assignment operator
Image &Image::operator=(Image &&source) {
  std::cout << "Moving and assigning " << &source << " to " << this << std::endl;
  if (this == &source) {
    return *this;
  }

  swap(source._image, this->_image);
  swap(source._imagePath, this->_imagePath);
  swap(source._width, this->_width);
  swap(source._height, this->_height);
  swap(source._channels, this->_channels);

  return *this;
}

// Destructor
Image::~Image() {
  if (!_image.empty()) {
    _image.release();
  }
  std::cout << "Destroying image " << this->_imagePath  << " at address " << this << std::endl;
}