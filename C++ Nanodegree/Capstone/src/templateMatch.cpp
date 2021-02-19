#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>

#include "templateMatch.h"

using namespace cv;

templateMatch::templateMatch(Image im) : _originalImage(im.getImage()) {}

std::vector<float> templateMatch::drawBoxes(Mat image, std::vector<std::string> templates) {

}

std::vector<std::string> templateMatch::templateImages() {
    std::vector<std::string> temp;
    std::string path = "/home/simon/Udacity/C++ Nanodegree/Capstone/images/templates";
    DIR* directory = opendir(path.c_str());
    struct dirent* file;
    while ((file = readdir(directory)) != nullptr) {
        std::string filename = file->d_name;
        if (filename != "." && filename != "..") {
            temp.push_back(filename);
        }
    }
    closedir;

    return temp;
}

void templateMatch::showProcessedImage() {
  const std::string named_Window("HSV road");
  namedWindow(named_Window);
  imshow(named_Window, _originalImage);
  waitKey(0);
}



















/*
void templateMatch::standardize() {
    cv::resize(_originalImage, _originalImage, cv::Size(64,128));
}

void templateMatch::colorTransformation() {
    cv::Mat tempImg;
    cv::cvtColor(_originalImage, tempImg, cv::COLOR_BGR2GRAY);
    _originalImage = tempImg;
}

void templateMatch::HOGfeatures() {
    int orient = 9;
    int pixPerCell = 8;
    int cellPerBlock = 2;
    bool vis = true;
    bool featureVector = false;
    cv::HOGDescriptor hog;
    std::vector<float> descriptors;
    std::vector<cv::Point> locations;

    hog.compute(_originalImage, descriptors, cv::Size(pixPerCell,pixPerCell), cv::Size(cellPerBlock,cellPerBlock), locations);

    cv::Mat HOGfeat(descriptors.size(), 1, CV_32FC1);

    for (int i = 0; i < descriptors.size(); i++) HOGfeat.at<float>(i,0)=descriptors.at(i);

    _HOGfeats = HOGfeat;
}
*/
