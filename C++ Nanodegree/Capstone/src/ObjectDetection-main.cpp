#include <iostream>
#include <string>
#include <memory>

#include "Image.h"
#include "templateMatch.h"

int main() {
    //std::cout << image.width << "\n" << image.height << std::endl;
    Image im("/home/simon/Udacity/C++ Nanodegree/Capstone/images/1.png");
    templateMatch p(im);
    
    std::vector<std::string> t = p.templateImages();
    for (auto &i : t) std::cout << i << " ";
    std::cout << std::endl;

    
    Image im2 = im;
    
    std::cout << im.getChannels() << " " << im.getWidth() << " " << im.getHeight() << std::endl;
    std::cout << im2.getChannels() << " " << im2.getWidth() << " " << im2.getHeight() << std::endl;
    std::cout << &im << " " << &im2 << "\n";
    im.showRawImg();
    im2.showRawImg();
    
    return 0;
}