#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>

#include "imageDetector.h"
#include "stopSignContours.h"

using namespace cv;

// Constructor
imageDetector::imageDetector() {
    templateImages();
    stopSignDetector(_templates);
}

// Browse through image-folder and appends shared pointers to valid images
void imageDetector::templateImages() {
    // Browse through relative images path for images to draw on
    std::string path = "../images/";
    DIR* directory = opendir(path.c_str());
    
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
            _img = std::make_shared<Image>(path+filename);
            _templates.emplace_back(_img);
        } else {
            std::cout << "'" << filename << "'" << " doesn't have a valid format" << std::endl;
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

// Detect stop-signs on images pointed to in vector until user abort
void imageDetector::stopSignDetector(std::vector<std::shared_ptr<Image>> stopsigns) {
    char condition;
    int i = 0;
    
    // Loop until user presses "q"
    while (condition != 'q') {
        
        // Restart loop if end reached
        if (i == stopsigns.size()) {
            i = 0;
        }

        // Create object with pointer to image
        StopSignContours sign(stopsigns[i]);

        // Draw contours around stop-sign pointed to
        sign.drawContours();

        // Retrieve user-input
        condition = sign.getKey();
        i++;
    }

    return;
}