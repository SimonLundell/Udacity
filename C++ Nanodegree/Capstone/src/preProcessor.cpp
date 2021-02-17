#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "preProcessor.h"

preProcessor::preProcessor() {}

void preProcessor::standardize() {}

void preProcessor::spatialTransformation() {}

void preProcessor::colorTransformation() {
    cv::Mat HSV_img;
    cv::cvtColor(getImage(), HSV_img, cv::COLOR_BGR2HSV);
    _processedImg = HSV_img;
}

void preProcessor::showHSVImage() {
  const std::string named_Window("HSV road");
  cv::namedWindow(named_Window);
  cv::imshow(named_Window, _processedImg);
  cv::waitKey(0);
}