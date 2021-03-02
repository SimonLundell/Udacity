#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>

#include "ImageDetector.h"
#include "StopSignContours.h"

using namespace cv;

// Constructor
// Req. ID OOP-3
// Req. ID OOP-4
// Req. ID OOP-5
imageDetector::imageDetector() : _path("../images/") {
    templateImages();
    stopSignDetector(_templates);
}

// Browse through image-folder and appends shared pointers to valid images
void imageDetector::templateImages() {
    // Browse through relative images path for images to draw on
    //std::string path = "../images/";
    DIR* directory = opendir(_path.c_str());
    
    // If no directory found, write error
    if (directory == nullptr) {
        std::cerr << "No valid directory given, abort" << std::endl;
        return;
    }
    // While directory is open, check the filename
    struct dirent* file;
    while ((file = readdir(directory)) != nullptr) {
        std::string filename = file->d_name;
        
        // If valid image, make a shared pointer to the Image object and add to template vector
        if (pathCheck(filename)) {
            _templates.emplace_back(_path+filename);
        } else {
            std::cout << "'" << filename << "'" << " doesn't have a valid format" << "\n";
        }
    }
    closedir;

    return;
}

// Check valid image-format
bool imageDetector::pathCheck(std::string path) {
    
    // Make ending all lower case for comparison
    std::for_each(path.begin(), path.end(), [](char &c){ c = ::tolower(c); });

    // Compare for the most common image-formats (more supported but not added)
    if (path.find(".jpeg") != std::string::npos) { return true; } 
    else if (path.find(".jpg") != std::string::npos) { return true; }
    else if (path.find(".png") != std::string::npos) { return true; }
    else if (path.find(".bmp") != std::string::npos) { return true; }
    else { return false; }
}

// Req. ID MM-2
// Detect stop-signs on images pointed to in vector until user abort
void imageDetector::stopSignDetector(std::vector<std::string> stopSigns) {
    char condition;
    int i = 0;
    
    // Checking so that stopsign vector is populated
    if (stopSigns.empty()) {
        std::cerr << "No images found, check path" << std::endl;
        return;
    }
    
    // Loop until user presses "q"
    while (condition != 'q') {
        
        // Restart loop if end or beginning reached
        if (condition == 'd' && i == stopSigns.size()) {
            i = 0;
        } else if (condition == 'a' && i == -1) {
            i = stopSigns.size() - 1;
        }
        
        // Create Image object with pointer to image
        _img = std::make_shared<Image>(stopSigns[i]);
        
        // Create stop-sign object with image pointed to
        StopSignContours stopSign(_img);

        // Draw contours around stop-sign pointed to
        stopSign.drawContours();

        // Retrieve user input
        condition = stopSign.getKey();

        // Increase or decrease counter depending on user input
        (condition == 'd') ? i++ : i--;
    }
    return;
}