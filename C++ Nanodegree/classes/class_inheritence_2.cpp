// Example solution for Rectangle and Square friend classes
#include <assert.h>

// Declare class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square {
    public:
    Square(int side_) : side(side_) {}
    friend class Rectangle;
    
    private:
    int side;
};
// Add public constructor to Square, initialize side
    // Add friend class Rectangle

    // Add private attribute side
class Rectangle {
    public:
    Rectangle(Square &s);
    int Area();
    
    private:
    int width{0};
    int height{0};
};
// Define class Rectangle
    // Add public function to Rectangle: Area()
    
    // Add private attributes width, height;

// Define a Rectangle constructor that takes a Square
Rectangle::Rectangle(Square &s) : width(s.side), height(s.side) {};
// Define Area() to compute area of Rectangle
int Rectangle::Area() { return width*height; }
// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}