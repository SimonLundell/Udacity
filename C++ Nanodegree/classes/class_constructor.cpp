#include <cassert>

class Date {
 public:
  Date(int d, int m, int y) {// Constructor. We are instantiating the data members
                             // Instead of assigning day = d etc., we are taking advantage of our mutators to not risk inputting invalid values
    Day(d);
    Month(m);
    Year(y);
  };

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

/* Alternative way to define the constructor outside the class.
Date::Date(int d, int m, int y) {
    Day(d);
    Month(m);
    Year(y);
}
*/
// Test in main. Asserts will fail because of Udacity put in asserts out of bounds
int main() {
  Date date(29,8,1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
}