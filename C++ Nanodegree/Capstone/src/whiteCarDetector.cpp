#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>
#include <iostream>

#include "whiteCarDetector.h"

using namespace cv;

const int H_max = 180;
const int S_max = 255;
const int V_max = 255;
int alpha_slider;
int low_H, low_S, low_V;
int high_H = H_max;
int high_S = S_max;
int high_V = V_max;
Mat src;

static void on_H_Low( int, void* )
{
   low_H = min(H_max - 1, low_H);
   setTrackbarPos("low_H", "HSV", low_H);
}

static void on_H_High( int, void* )
{
   high_H = max(high_H, low_H+1);
   setTrackbarPos("high_H", "HSV", high_H);
}


static void on_S_Low( int, void* )
{
    low_S = min(S_max - 1, low_S);
    setTrackbarPos("low_S", "HSV", low_S);
}

static void on_S_High( int, void* )
{
   high_S = max(high_S, low_S+1);
   setTrackbarPos("high_S", "HSV", high_S);
}

static void on_V_Low( int, void* )
{
    low_V = min(V_max - 1, low_V);
    setTrackbarPos("low_V", "HSV", low_V);
}

static void on_V_High( int, void* )
{
   high_V = max(high_V, low_V+1);
   setTrackbarPos("high_V", "HSV", high_V);
}

CarDetector::CarDetector(Image& im) : _img(im), _copiedImage(im) {
    applyMask(_copiedImage);
    //std::cout << "Linetracker " << &_img << std::endl;
}

//new
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

void CarDetector::applyMask(Image &img) {
    src = _img._image;
    namedWindow("HSV", WINDOW_AUTOSIZE); // Create Window
    createTrackbar( "low_H", "HSV", &low_H, H_max, on_H_Low );
    createTrackbar( "high_H", "HSV", &high_H, H_max, on_H_High );
    createTrackbar( "low_S", "HSV", &low_S, S_max, on_S_Low );
    createTrackbar( "high_S", "HSV", &high_S, S_max, on_S_High );
    createTrackbar( "low_V", "HSV", &low_V, V_max, on_V_Low );
    createTrackbar( "high_V", "HSV", &high_V, V_max, on_V_High );

    //on_trackbar( alpha_slider, 0 );
    //on_trackbar2( alpha_slider, 0 );
    //on_trackbar3( alpha_slider, 0 );
    Mat hsvImage;
    cvtColor(_copiedImage._image, hsvImage, COLOR_RGB2HSV);
    Mat output, canny;
    std::vector<std::vector<Point>>contours;
    //std::vector<Vec4i> hierarchy;
    /*
    while (true){
        inRange(hsvImage, Scalar(low_H, low_S, low_V), Scalar(H_max, S_max, V_max), output);
        inRange(hsvImage, Scalar(low_H, low_S, low_V), Scalar(H_max, S_max, V_max), output);
        imshow("HSV", src);
        imshow("HSV", output);
    
        char key = (char) waitKey(30);
        if (key == 'q' || key == 27) {
            break;
        }
        

    }
    */
    inRange(hsvImage, Scalar(113, 208, 70), Scalar(180, 255, 255), output);
    
    Canny(output, canny,100,200);
    findContours(canny, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
    //for (auto &i : contours) std::cout << i << "\n";
    //imshow("test", canny);

    Mat drawing = Mat::zeros(canny.size(), CV_8UC3);

    for (int i = 0; i< contours.size(); i++)
    {
        Scalar color = Scalar( 255,255,255);
        drawContours( _img._image, contours, i, color, 2 );
    }

    std::vector<Point> ConvexHullPoints = contoursConvexHull(contours);

    polylines( _img._image, ConvexHullPoints, true, Scalar(0,255,0), 4 );
    imshow("Contours", _img._image);
    
    waitKey(0);
    
}