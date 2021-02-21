#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>
#include <tuple>

#include "templateMatch.h"

using namespace cv;

templateMatch::templateMatch(Image &im) : _orgIm(im), _originalImage(im._image) {
    _templates = templateImages();
    _boxes = findMatches(_templates);
    drawBoxes(_orgIm, _boxes);
}

std::vector<std::vector<Point>> templateMatch::findMatches(std::vector<Mat> templates) {
    std::vector<std::vector<Point>> boxes;
    Image copied(_orgIm, IMREAD_GRAYSCALE); // New
    Mat image = copied._image; // New
    Mat matchOutput;
    Point min_loc, max_loc, top_left, bottom_right;
    double min_val, max_val;
    auto method = TM_CCOEFF_NORMED;

    for (auto &temp : templates) {
        std::vector<Point> points{};
        matchTemplate(image, temp, matchOutput, method);
        minMaxLoc(matchOutput, &min_val, &max_val, &min_loc, &max_loc);
        if (method == TM_SQDIFF_NORMED || method == TM_SQDIFF) {
            top_left = min_loc;
        } else {
            top_left = max_loc;
        }
        bottom_right.x = top_left.x + temp.cols;
        bottom_right.y = top_left.y + temp.rows;
        points.emplace_back(top_left);
        points.emplace_back(bottom_right);
        boxes.emplace_back(points);
    }
    
    return boxes;
}

void templateMatch::drawBoxes(Image &image, std::vector<std::vector<Point>> boxes) {
    for (auto &i : boxes) {
        rectangle(image._image, i[0], i[1], Scalar(0,255,0), 3);
        //std::cout << i[0] << " " << i[1] <<"\n";
        const std::string named_Window("HSV road");
        namedWindow(named_Window);
        imshow(named_Window, image._image);
        waitKey(0);
    }

}

std::vector<Mat> templateMatch::templateImages() {
    std::vector<Mat> temp;
    std::string path = "/home/simon/Udacity/C++ Nanodegree/Capstone/images/templates";
    DIR* directory = opendir(path.c_str());
    struct dirent* file;
    while ((file = readdir(directory)) != nullptr) {
        std::string filename = file->d_name;
        //if (filename != "." && filename != ".." && filename != ".DS_Store") {
        if (filename.find(".jpg") != std::string::npos || filename.find(".png") != std::string::npos ||
            filename.find(".jpeg") != std::string::npos) {
            Mat img = imread((path+"/"+filename), IMREAD_GRAYSCALE);
            if (img.empty()) {
                std::cerr << "Couldn't load template image\n";
                return {};
            }
            temp.emplace_back(img);
        }
    }
    closedir;

    return temp;
}

void templateMatch::printTemplates() { 
    for (auto &i : _templates) {
        std::string named("template");
        namedWindow(named);
        imshow(named, i);
        waitKey(0);
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
