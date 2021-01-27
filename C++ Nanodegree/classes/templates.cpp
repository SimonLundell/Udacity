#include <assert.h>

template <typename M> // Define a template of type M
M Product(M a, M b) { return a * b; } // Returntype M, when calling Product, given arguments "a" and "b" will be 
                                      //multiplied and returned with the datatype specified in the call.

template <typename m>
m Max(m a, m b) { return a > b ? a : b; }

template <typename T>
T average(T a, T b) { return (a + b) / 2; } 

int main() { 
  assert(Product<int>(10, 2) == 20); // Specifying Product to take 2 ints
  // By not speciyfing the types here and below, we invoke deduction
  assert(Max(10, 50) == 50);
  assert(Max(5.7, 1.436246) == 5.7);
  assert(average(2.0,5.0) == 3.5); 
}