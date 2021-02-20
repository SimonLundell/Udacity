#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

struct Image {
  public:
    // Constructors
    //Image();
    Image(const std::string filename);
    Image(const Image &source);
    
    // Helpers
    void showRawImg();

    // Variables
    cv::Mat _image{};
    std::string const _imagePath{};
    int _width;
    int _height;
    int _channels;

};
#endif