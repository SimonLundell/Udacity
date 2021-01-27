#include <assert.h>
#include <cmath>

#define PI 3.14159;

class Shape {
  public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};

class Rectangle : public Shape {
  public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
     // "override" not required but best practice.
     // Remember too kepp the const in the definition!! Can't compile otherwise
    double Area() const override { return width_ * height_; }
    double Perimeter() const override { return width_ * 2 + height_ * 2; }
    
  private:
    double width_, height_;
};

class Circle : public Shape {
  public:   
    Circle(double radius) : radius_(radius) {}
    
    double Area() const override { return pow(radius_, 2) * PI; } // Have to have PI last, otherwise '*' complains...
    double Perimeter() const override { return 2 * radius_ * PI; }
    
  private:
    double radius_;
    
};
int main() {
  double epsilon = 0.1; // useful for floating point equality

  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}