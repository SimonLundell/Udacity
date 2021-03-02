# Readme

## Introduction
This is the final project for the Udacity C++ Nanodegree. The purpose of this project is to:
* Use good OOP guidelines
* Be able to draw an outline around stop signs through appropriate openCV funnctions
* Easily maneouver back and forth between the pictures with user input
* Handle the pictures in a memory efficient way with smart pointers in combination with rule of five

The purpose is _not_ to make a perfect sign detection

**Example result:**

![Stop sign example](https://user-images.githubusercontent.com/58783863/109550893-2657b300-7ad0-11eb-961c-753e8468b6e8.jpg)


## Dependencies
* Cmake >= 2.8
    * Make >= 4.1 (Linux / Mac), 3.81 (windows)
* OpenCV >= 4.1
    * Linux install here https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html
    * Windows install here https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html
* gcc / g++ >= 5.1
* Images of traffic-signs in "images" folder

## Basic build instructions
* Clone this repository
* Make a build directory and "cd build"
* Run cmake .. && make
* Run it with ./object_detection

## Additional information
The project consists of:
* ObjectDetection-main.cpp
   * Only starts the execution
* Image.h / Image.cpp
   * Creating an Image struct which allows for creating, copying, moving and deleting Image objects (together with openCV)
* ImageDetector.h / ImageDetector.cpp
   * Will find the stop-sign images in "/images", create Image-structs from them and passing shared_ptr of Image to "StopSignContours" for detection and drawing
* StopSignContours.h / StopSignContours.cpp
   * Takes a shared_ptr to an Image as an argument, copies this image, extracts the relevant features and displays the Image copy with drawn contours around the stop-sign

# The project fulfills the following criterias
__Please find the ID in the code as specified below__
## Loops, Functions, I/O
**Criteria**
* LFIO-1: The project demonstrates an understanding of C++ functions and control structures.
* LFIO-2: The project reads data from a file and process the data, or the program writes data to a file.
* LFIO-3: The project accepts user input and processes the input.

## Object Oriented Programming
**Criteria**
* OOP-1: The project uses Object Oriented Programming techniques.
* OOP-2: Classes use appropriate access specifiers for class members.
* OOP-3: Class constructors utilize member initialization lists.
* OOP-4: Classes abstract implementation details from their interfaces.
* OOP-5: Classes encapsulate behavior.

## Memory Management
**Criteria**
* MM-1: The project makes use of references in function declarations.
* MM-2: The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
* MM-3: The project follows the Rule of 5.
* MM-4: The project uses smart pointers instead of raw pointers.
