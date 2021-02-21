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
    Image(const Image &source, cv::ImreadModes colorScheme);
    ~Image();
    
    // Helpers
    void showRawImg();

    // Variables
    cv::Mat _image{};
    std::string _imagePath{};
    int _width;
    int _height;
    int _channels;

};
#endif