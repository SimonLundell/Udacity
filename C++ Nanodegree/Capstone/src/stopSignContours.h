#ifndef WHITECARDETECTOR_H
#define WHITECARDETECTOR_H

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>

#include "Image.h"

using namespace cv;

class StopSignContours {
  public:
    // Constructor
    StopSignContours(std::shared_ptr<Image> im);

    // Functions to find process the image and extract suitable points
    void drawContours();
    std::vector<Point> contoursConvexHull(std::vector<std::vector<Point>> contours);

    // Accessor to user input
    char getKey(){ return _key; }

  private:
    std::shared_ptr<Image> _img;
    char _key{};
};
#endif