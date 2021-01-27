#include <cassert>

class Date {
 public:
  Date(int d, int m, int y);
  int Day() { return day; }
  void Day(int d) {
    if (d >= 1 && d <= 31) day = d;
  }
  int Month() { return month; }
  void Month(int m) {
    if (m >= 1 && m <= 12) month = m;
  }
  int Year() { return year; }
  void Year(int y) { year = y; }

 private:
  int day{1};
  int month{1};
  int year{0};
};

Date::Date(int d, int m, int y) { // Constructor defined outside the class, this is for hidden abstraction. Using "scope resolution" to connect the constructor with the class
    Day(d);
    Month(m);
    Year(y);
  }

// Test in main. Asserts will fail because of Udacity put in asserts out of bounds
int main() {
  Date date(8,29,1981);
  assert(date.Day() == 8);
  assert(date.Month() == 29);
  assert(date.Year() == 1981);
}