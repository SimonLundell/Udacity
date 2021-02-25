#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>
#include <tuple>

#include "templateMatch.h"
#include "whiteCarDetector.h"

using namespace cv;

templateMatch::templateMatch() {
    templateImages();
    stopSignDetector(_templates);
}

void templateMatch::templateImages() {
    std::string path = "/home/simon/Udacity/C++ Nanodegree/Capstone/images/";
    DIR* directory = opendir(path.c_str());
    if (directory == nullptr) {
        std::cerr << "No valid directory given, abort" << std::endl;
        return;
    }
    struct dirent* file;
    while ((file = readdir(directory)) != nullptr) {
        std::string filename = file->d_name;
        if (pathCheck(filename)) {
            _img = std::make_shared<Image>(path+filename);
            _templates.emplace_back(_img);
        }
    }
    closedir;
    return;
}

bool templateMatch::pathCheck(std::string path) {
    //char c;
    std::for_each(path.begin(), path.end(), [](char &c){ c = ::tolower(c); });
    if (path.find(".jpeg") != std::string::npos) { return true; } 
    else if (path.find(".jpg") != std::string::npos) { return true; }
    else if (path.find(".png") != std::string::npos) { return true; }
    else if (path.find(".JPG") != std::string::npos) { return true; }
    else { return false; }
}

void templateMatch::stopSignDetector(std::vector<std::shared_ptr<Image>> stopsigns) {
    for (int i = 0; i < stopsigns.size(); i++) {
        CarDetector car(stopsigns[i]);
    }
    return;
}