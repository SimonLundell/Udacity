#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "Image.h"

class preProcessor {
  public:
    // Constructor
    preProcessor(Image * im);

    // Functions to standardize the image
    void standardize();
    void HOGfeatures();
    void colorTransformation();
    void showHSVImage();

  private:
    cv::Mat _originalImage{};
    cv::Mat _processedImg{};
}; 
#endif