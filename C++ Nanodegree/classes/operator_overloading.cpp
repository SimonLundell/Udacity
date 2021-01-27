#include <assert.h>
#include <iostream>

class Point {
  public:
  // Has to set x and y = 0, otherwise it will not work.
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    // have to create a new Point (Point sum), because we are creating a third point by adding p1 and p2.
    Point operator+(const Point &p) { // const because we dont want to modify the object being called. We pass a reference to p2.
        Point sum;
        // Uncomment to see x/y and p.x/p.y
        //std::cout << x << " " << y;
        //std::cout << p.x << " " << p.y;
        sum.x = x + p.x; // Adding the current objects x (which is p1) with input object x (which is p2) and "moving" result into Point sum (p3).
        sum.y = y + p.y; // same as above
        return sum;
    }
    int x;
    int y;
};
// Test in main()
int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}