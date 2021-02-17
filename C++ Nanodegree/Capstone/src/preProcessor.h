#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "Image.h"

class preProcessor : public Image {
  public:
    // Constructor
    preProcessor();

    // Functions to standardize the image
    void standardize();
    void spatialTransformation();
    void colorTransformation();
    void showHSVImage();

  private:
    cv::Mat _processedImg{};
}; 
#endif