#include <iostream>
#include <string>
#include <memory>

#include "Image.h"
#include "preProcessor.h"

int main() {
    //std::cout << image.width << "\n" << image.height << std::endl;
    Image im("/home/simon/Udacity/C++ Nanodegree/Capstone/images/curved_lane.jpg");
    Image * pim = &im;
    preProcessor p(pim);
    p.colorTransformation();
    p.showHSVImage();
    
    std::cout << pim->getChannels() << " " << pim->getWidth() << " " << pim->getHeight() << std::endl;

    return 0;
}