#include <iostream>
#include <string>
#include <memory>

#include "Image.h"
#include "templateMatch.h"
#include "whiteCarDetector.h"

int main() {
    //std::cout << image.width << "\n" << image.height << std::endl;
    Image im;
    //Image im("/home/simon/Udacity/C++ Nanodegree/Capstone/images/bbox-example-image.jpg");
    //templateMatch p(im);
    //im.showRawImg();
    CarDetector k(im);
    //p.printTemplates();
    //p.createBoxes();

    /*
    Image im2 = im;
    
    std::cout << im.getChannels() << " " << im.getWidth() << " " << im.getHeight() << std::endl;
    std::cout << im2.getChannels() << " " << im2.getWidth() << " " << im2.getHeight() << std::endl;
    std::cout << &im << " " << &im2 << "\n";
    //im.showRawImg();
    //im2.showRawImg();
    p.showProcessedImage();
    */
    return 0;
}