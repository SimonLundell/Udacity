#ifndef TEMPLATEMATCH_H
#define TEMPLATEMATCH_H

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "Image.h"

using namespace cv;

class templateMatch {
  public:
    // Constructor
    templateMatch();

    // Functions to standardize the image
    //void showProcessedImage();
    // Functions
    void templateImages();
    void stopSignDetector(std::vector<std::shared_ptr<Image>> stopsigns);
    //std::vector<std::vector<Point>> findMatches(std::vector<Mat> templates);
    //void drawBoxes(Image &image, std::vector<std::vector<Point>> boxes);
    //void printTemplates();
    //Image copiedIm(Image im, ImreadModes color);

    // Accessor / mutators
    std::vector<std::shared_ptr<Image>> getImages() { return _templates; }

  private:
    std::shared_ptr<Image> _img;
    std::vector<std::shared_ptr<Image>> _templates{};
    //std::vector<std::vector<Point>> _boxes{};
    //cv::Mat _HOGfeats{};
};
#endif


/*
void standardize();
void colorTransformation();
void HOGfeatures();
void SVM();
*/