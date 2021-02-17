cmake_minimum_required(VERSION 3.11.3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(Capstone)

find_package(OpenCV 4.1 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

file(GLOB project_SRCS src/*.cpp)

add_executable(object_detection ${project_SRCS})
target_link_libraries(object_detection ${OpenCV_LIBRARIES})