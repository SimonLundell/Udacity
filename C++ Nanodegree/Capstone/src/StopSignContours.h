#ifndef WHITECARDETECTOR_H
#define WHITECARDETECTOR_H

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>

#include "Image.h"

using namespace cv;

// Req. ID LFIO-2
// Req. ID OOP-1
// Req. ID OOP-4
// Req. ID OOP-5
class StopSignContours {
  public:
    // Constructor
    StopSignContours(std::shared_ptr<Image> im);

    // Functions to find process the image and extract suitable points
    void drawContours();
    std::vector<Point> contoursConvexHull(std::vector<std::vector<Point>> contours);
    bool waitGoodKey();

    // Req. ID OOP-2
    // Req. ID MM-1
    // Accessor to user input
    char getKey(){ return _key; }
    Mat& getCopiedImage() { return _copiedImage._image; }
    std::string& getCopiedImagePath() { return _copiedImage._imagePath; }

  private:
    std::shared_ptr<Image> _img;
    Image _copiedImage{};
    char _key{};
};
#endif