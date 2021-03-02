#ifndef TEMPLATEMATCH_H
#define TEMPLATEMATCH_H

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "Image.h"

using namespace cv;

// Req. ID LFIO-2
// Req. ID OOP-1
class imageDetector {
  public:
    // Constructor
    imageDetector();

    // Functions to find images, check valid path to image and detect stop signs
    void templateImages();
    bool pathCheck(std::string path);
    void stopSignDetector(std::vector<std::string> stopsigns);

  // Initializing private variables
  private:
    // Req. ID MM-4
    std::shared_ptr<Image> _img{};
    std::vector<std::string> _templates{};
    const std::string _path{};
};
#endif