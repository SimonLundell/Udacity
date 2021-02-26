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

    // Functions
    void applyMask(Image &img);
    std::vector<Point> contoursConvexHull( std::vector<std::vector<Point> > contours );

    // Accessors / mutators
    char getKey(){ return _key; }

  private:
    std::shared_ptr<Image> _img{};
    Image _copiedImage{*_img};
    char _key{};
};
#endif