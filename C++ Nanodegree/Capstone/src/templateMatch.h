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
    templateMatch(Image &im);

    // Functions to standardize the image
    void showProcessedImage();
    std::vector<Mat> templateImages();
    std::vector<std::vector<Point>> findMatches(std::vector<Mat> templates);
    void drawBoxes(Image &image, std::vector<std::vector<Point>> boxes);
    void printTemplates();
    Image copiedIm(Image im, ImreadModes color);

  private:
    Image &_orgIm;
    Mat _originalImage{};
    std::vector<Mat> _templates{};
    std::vector<std::vector<Point>> _boxes{};
    //cv::Mat _HOGfeats{};
};
#endif


/*
void standardize();
void colorTransformation();
void HOGfeatures();
void SVM();
*/