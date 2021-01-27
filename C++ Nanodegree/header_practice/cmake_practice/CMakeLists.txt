cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 17)
project(simon_cmake)
add_executable(test_executable src/increment_and_sum.cpp src/main.cpp src/vect_add_one.cpp)
