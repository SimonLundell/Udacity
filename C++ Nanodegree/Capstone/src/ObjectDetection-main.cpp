#include <iostream>
#include <string>
#include <memory>

#include "Image.h"
#include "preProcessor.h"

int main() {
    //std::cout << image.width << "\n" << image.height << std::endl;
    preProcessor p;
    p.colorTransformation();
    p.showHSVImage();
    Image im("/home/simon/Udacity/C++ Nanodegree/Capstone/images/curved_lane.jpg");
    std::cout << im.getChannels() << " " << im.getWidth() << " " << im.getHeight() << std::endl;

    return 0;
}