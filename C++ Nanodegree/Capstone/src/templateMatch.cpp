#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>

#include "templateMatch.h"

using namespace cv;

templateMatch::templateMatch(Image im) : _originalImage(im._image) {
    _templates = templateImages();
    _boxes = drawBoxes(_originalImage, _templates);
}

std::vector<Point> templateMatch::drawBoxes(Mat image, std::vector<std::string> templates) {
    std::vector<Point> boxes;
    Mat matchOutput;
    double min_val, max_val;
    Point min_loc, max_loc, top_left, bottom_right;
    Mat readTemp;
    for (auto &temp : templates) {
        readTemp = imread(temp, IMREAD_GRAYSCALE);
        matchTemplate(image, readTemp, matchOutput, TM_CCOEFF_NORMED);
        minMaxLoc(matchOutput, &min_val, &max_val, &min_loc, &max_loc);
        top_left = max_loc;
        bottom_right.x = top_left.x + readTemp.cols;
        bottom_right.y = top_left.y + readTemp.rows;
        boxes.emplace_back((top_left, bottom_right));
    }
    //std::cout << results.size() << "\n";
    
    return boxes;
}

std::vector<std::string> templateMatch::templateImages() {
    std::vector<std::string> temp;
    std::string path = "/home/simon/Udacity/C++ Nanodegree/Capstone/images/templates";
    DIR* directory = opendir(path.c_str());
    struct dirent* file;
    while ((file = readdir(directory)) != nullptr) {
        std::string filename = file->d_name;
        if (filename != "." && filename != "..") {
            temp.push_back(path + "/" + filename);
        }
    }
    closedir;

    return temp;
}

void templateMatch::printTemplates() { 
    for (auto &i : _templates) {
        Mat im = imread(i);
        std::string named("template");
        namedWindow(named);
        imshow(named, im);
        waitKey(0);
        //std::cout << i << " "; std::cout << std::endl; 
    }
        
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
