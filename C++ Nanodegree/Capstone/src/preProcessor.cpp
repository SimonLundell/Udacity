#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "preProcessor.h"

preProcessor::preProcessor(Image * im) : _originalImage(im->getImage()) {}

void preProcessor::standardize() {}

void preProcessor::HOGfeatures() {}

void preProcessor::colorTransformation() {
    cv::Mat tempImg;
    cv::cvtColor(_originalImage, tempImg, cv::COLOR_BGR2GRAY);
    _processedImg = tempImg;
}

void preProcessor::showHSVImage() {
  const std::string named_Window("HSV road");
  cv::namedWindow(named_Window);
  cv::imshow(named_Window, _processedImg);
  cv::waitKey(0);
}