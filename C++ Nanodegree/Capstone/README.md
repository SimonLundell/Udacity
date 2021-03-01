# Readme

## Introduction
This is the final project for the Udacity C++ Nanodegree. The purpose of this project is to:
* Use good OOP guidelines
* Be able to draw an outline around stop signs through appropriate openCV funnctions
* Easily maneouver back and forth between the pictures with user input
* Handle the pictures in a memory efficient way with smart pointers in combination with rule of five

The purpose is _not_ to make a perfect sign detection

Example result:

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
