#ifndef WHITECARDETECTOR_H
#define WHITECARDETECTOR_H

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>

#include "Image.h"

using namespace cv;

class CarDetector {
  public:
    CarDetector(Image &im);

    void applyMask(Image &img);
    void createEdges();
    // new
    std::vector<Point> contoursConvexHull( std::vector<std::vector<Point> > contours );

  private:
    Image _img;
    Image _copiedImage{};
    //Image _edgeImage;
};
#endif