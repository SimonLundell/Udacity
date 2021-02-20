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
    templateMatch(Image im);

    // Functions to standardize the image
    void showProcessedImage();
    std::vector<Point> drawBoxes(Mat image, std::vector<std::string> templates);
    std::vector<std::string> templateImages();
    void printTemplates();
    //void createBoxes() { _boxes =  }

  private:
    Mat _originalImage{};
    std::vector<std::string> _templates{};
    std::vector<Point> _boxes{};
    //cv::Mat _HOGfeats{};
};
#endif


/*
void standardize();
void colorTransformation();
void HOGfeatures();
void SVM();
*/