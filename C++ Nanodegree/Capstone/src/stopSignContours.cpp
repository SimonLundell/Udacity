#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>
#include <iostream>

#include "stopSignContours.h"

using namespace cv;

// Constructor
StopSignContours::StopSignContours(std::shared_ptr<Image> im) : _img(im), _copiedImage(*im) {}

// Take vector of contours and return a new vector of points using convexHull method
std::vector<Point> StopSignContours::contoursConvexHull( std::vector<std::vector<Point>> contours)
{
    std::vector<Point> result;
    std::vector<Point> pts;
    for ( size_t i = 0; i< contours.size(); i++)
        for ( size_t j = 0; j< contours[i].size(); j++)
            pts.push_back(contours[i][j]);
    convexHull(pts, result);
    
    return result;
}

// Copy current image pointed to, apply filter and draw lines on copy. Destroy copy when done.
void StopSignContours::drawContours() {
    Mat3b hsvImage;
    Mat1b output, mask1, mask2;
    Mat canny, drawing;
    std::vector<std::vector<Point>>contours;

    // Creating HSV image from copy
    cvtColor(_copiedImage._image, hsvImage, COLOR_BGR2HSV);
    
    // Defining ranges for red (need 2 since red wraps 180)
    inRange(hsvImage, Scalar(0, 210, 82), Scalar(10, 255, 255), mask1);
    inRange(hsvImage, Scalar(170, 210, 82), Scalar(180, 255, 255), mask2);

    // Final mask
    output = mask1 | mask2;

    // Draw contours from mask (method can be modified)
    Canny(output, canny, 150, 250);
    findContours(canny, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
    
    // If no contours found, skip image
    if (contours.size() == 0) {
        std::cout << _copiedImage._imagePath << " didn't detect any contours. Go to next!" << std::endl;
    } else {
        
        // Otherwise, make points between contours using convexHull function and draw lines between points on copied image
        std::vector<Point> ConvexHullPoints = contoursConvexHull(contours);
        polylines(_copiedImage._image, ConvexHullPoints, true, Scalar(0,255,0), 4 );
        
        // Show copied image with lines around stopsign
        imshow("Stop sign", _copiedImage._image);
    }
    std::cout << "'d' : next image. 'a' : previous image. 'q' : quit" << std::endl;
    
    // Wait for a valid key input
    while (!waitGoodKey());
}

// Wait for a valid key input from user
bool StopSignContours::waitGoodKey() {
    _key = waitKey(0);
    if (_key == 'a' || _key == 'd' || _key == 'q') {
        return true;
    }
    std::cout << "Invalid key" << std::endl;
}