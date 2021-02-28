#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>
#include <tuple>

#include "imageDetector.h"
#include "stopSignContours.h"

using namespace cv;

imageDetector::imageDetector() {
    templateImages();
    stopSignDetector(_templates);
}

void imageDetector::templateImages() {
    std::string path = "../images/";
    DIR* directory = opendir(path.c_str());
    if (directory == nullptr) {
        std::cerr << "No valid directory given, abort" << std::endl;
        return;
    }
    struct dirent* file;
    while ((file = readdir(directory)) != nullptr) {
        std::string filename = file->d_name;
        if (pathCheck(filename)) {
            _img = std::make_unique<Image>(path+filename);
            _templates.emplace_back(_img);
        }
    }
    closedir;
    return;
}

bool imageDetector::pathCheck(std::string path) {
    std::for_each(path.begin(), path.end(), [](char &c){ c = ::tolower(c); });
    if (path.find(".jpeg") != std::string::npos) { return true; } 
    else if (path.find(".jpg") != std::string::npos) { return true; }
    else if (path.find(".png") != std::string::npos) { return true; }
    else if (path.find(".JPG") != std::string::npos) { return true; }
    else { return false; }
}

void imageDetector::stopSignDetector(std::vector<std::shared_ptr<Image>> stopsigns) {
    char condition;
    int i = 0;
    
    while (condition != 'q') {
        if (i == stopsigns.size()) {
            i = 0;
        }
        StopSignContours sign(stopsigns[i]);
        condition = sign.getKey();
        i++;

        
    }

    return;
}