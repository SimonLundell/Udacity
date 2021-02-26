#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>
#include <iostream>

#include "stopSignContours.h"

using namespace cv;

StopSignContours::StopSignContours(std::shared_ptr<Image> im) : _img(im) {
    applyMask(_copiedImage);
}

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

void StopSignContours::applyMask(Image &copiedImg) {
   
    Mat3b hsvImage;
    Mat1b output, mask1, mask2;
    Mat canny, drawing;
    cvtColor(copiedImg._image, hsvImage, COLOR_BGR2HSV);
    
    std::vector<std::vector<Point>>contours;

    inRange(hsvImage, Scalar(0, 210, 82), Scalar(10, 255, 255), mask1);
    inRange(hsvImage, Scalar(170, 210, 82), Scalar(180, 255, 255), mask2);

    output = mask1 | mask2;

    Canny(output, canny,100,200);
    findContours(canny, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
    
    if (contours.size() == 0) {
        std::cout << this->_img->_imagePath << " didn't detect any contours. Skipping" << std::endl;
    } else {
        drawing = Mat::zeros(canny.size(), CV_8UC3);

        std::vector<Point> ConvexHullPoints = contoursConvexHull(contours);

        polylines(_copiedImage._image, ConvexHullPoints, true, Scalar(0,255,0), 4 );
        imshow("Contours", _copiedImage._image);
        
        std::cout << "Next image, press any key! \nQuit program, press 'q'" << std::endl;

        _key = waitKey(0);
    }
}