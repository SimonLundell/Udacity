#include <string>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

class Image {
  public:
    Image();
    void showImg();
    int width;
    int height;

  private:
    cv::Mat _image{};
    std::string const _imagePath{};
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
