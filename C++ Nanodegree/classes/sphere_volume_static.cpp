#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
 public:
   static float Volume(int radius) { // Since the function is defined as static, we can access it without creating an object of Sphere first. See in int main.
       return pi_ * 4/3 * pow(radius,3);
   }

 private:
  static float constexpr pi_{3.14159};
};

// Test
int main(void) {
  assert(abs(Sphere::Volume(5) - 523.6) < 1);
}