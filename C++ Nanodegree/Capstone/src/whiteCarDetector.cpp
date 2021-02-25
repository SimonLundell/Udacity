#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>
#include <iostream>

#include "whiteCarDetector.h"

using namespace cv;

CarDetector::CarDetector(std::shared_ptr<Image> im) : _img(im), _copiedImage(*im) {
    applyMask(_copiedImage);
}

std::vector<Point> CarDetector::contoursConvexHull( std::vector<std::vector<Point> > contours )
{
    std::vector<Point> result;
    std::vector<Point> pts;
    for ( size_t i = 0; i< contours.size(); i++)
        for ( size_t j = 0; j< contours[i].size(); j++)
            pts.push_back(contours[i][j]);
    convexHull( pts, result );
    return result;
}

void CarDetector::applyMask(Image &copiedImg) {
   
    Mat hsvImage;
    cvtColor(copiedImg._image, hsvImage, COLOR_RGB2HSV);
    Mat output, canny;
    std::vector<std::vector<Point>>contours;

    inRange(hsvImage, Scalar(113, 190, 70), Scalar(180, 255, 255), output);
    
    Canny(output, canny,150,200);
    findContours(canny, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

    Mat drawing = Mat::zeros(canny.size(), CV_8UC3);

    std::vector<Point> ConvexHullPoints = contoursConvexHull(contours);

    polylines(_img->_image, ConvexHullPoints, true, Scalar(0,255,0), 4 );
    imshow("Contours", _img->_image);
    
    waitKey(0);
}