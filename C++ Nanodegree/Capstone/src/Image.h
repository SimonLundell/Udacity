#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

class Image {
  public:
    // Constructors
    //Image();
    Image(const std::string filename);
    
    // Helpers
    void showRawImg();

    // Accessors / Mutators
    cv::Mat getImage() { return _image; }
    int getWidth() { return _width; }
    int getHeight() { return _height; }
    int getChannels() { return _channels; }

  private:
    cv::Mat _image{};
    std::string const _imagePath{};
    int _width;
    int _height;
    int _channels;

};

class Classifier {
    public:
      // Constructor
      Classifier(){}

      // accessors / mutators
      
      
      //functions
      void trackLane();
      // make grayscale
      // extract cannyfeatures
      // overlay lanes
      // merge original (tracklane?)

    private:
      
};
#endif