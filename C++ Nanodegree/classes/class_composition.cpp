#include <iostream>
#include <cmath>
#include <assert.h>
// Define PI as a "macro"
#define PI 3.14159;


// Define LineSegment struct with one variable
struct LineSegment {
public:
    double length;
};

// Define Circle class
class Circle {
public:
    Circle(LineSegment& radius); // Composition is defined in the constructor here (constructor definition outside class, just for fun);
    double Area(); // Declare function Area().

private:
    LineSegment& radius_; // radius_ defined as a LineSegment type
};

// Constructor for the Circle class. radius_ = radius, both with types LineSegment.
Circle::Circle(LineSegment& radius) : radius_(radius) {}

double Circle::Area() 
{
    return pow(Circle::radius_.length, 2) * PI; // Define function "Area()".
}
// Just testing if I can use the struct in another function.
class twoLines {
    public:
      twoLines(LineSegment n); // declare constructor
      LineSegment line;
      int lineSquared() { std::cout << pow(line.length, 2) << "\n"; }
};
twoLines::twoLines(LineSegment n) : line(n) {} // define constructor
// Test in main()
int main() 
{
    LineSegment radius {3}; // Making a radius of type LineSegment with a value of 3.
    Circle circle(radius); // Sending the radius variable to circle (which takes a LineSegment type)
    twoLines(radius).lineSquared(); //twoLines() calls function with default values defined in class.
    assert(int(circle.Area()) == 28);
}