#include <iostream>
#include <string>
#include <memory>

#include "Image.h"

int main() {
    Image image;
    std::cout << image.width << "\n" << image.height << std::endl;
    image.showImg();
    

    return 0;
}