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

    // Functions
    void templateImages();
    void stopSignDetector(std::vector<std::shared_ptr<Image>> stopsigns);
    bool pathCheck(std::string path);

    // Accessor / mutators
    std::vector<std::shared_ptr<Image>> getImages() { return _templates; }

  private:
    std::shared_ptr<Image> _img;
    std::vector<std::shared_ptr<Image>> _templates{};
};
#endif