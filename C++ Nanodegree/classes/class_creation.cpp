#include <cassert>
#include <iostream>

class Date {
public:
  // Accessors
  int Day() { return day; }
  int Month() { return month; }
  int Year() { return year; }

  // Mutators
  void Day(int d) {
    if (d > 0 && d < 31) { // Inversion
      day = d;
    } else {
      std::cout << "Day out of bounds \n";
    }
  }
  void Month(int m) {
    if (m > 0 && m < 13) { // Inversion
      month = m;
    } else {
      std::cout << "Month out of bounds \n";
    }
  }
  void Year(int y) { year = y; }

  // Instantiators
private:
  int day{1};
  int month{1};
  int year{0};
};

// Test in main. Notice how c++ can differentiate from Accessor and mutator
// through the argument, even though the names are the same.
int main() {
  Date date;
  date.Day(15);
  date.Month(6);
  date.Year(1988);
  assert(date.Day() != -1);
  assert(date.Month() != 14);
  assert(date.Year() == 1988);
  std::cout << "The date is: " << date.Day() << "/" << date.Month() << "/"
            << date.Year() << "\n";
}
