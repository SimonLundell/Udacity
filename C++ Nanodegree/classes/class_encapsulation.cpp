#include <cassert>

class Date {
public:
  Date(int day, int month, int year); // Declare constructor

  int Day() const { return day_; } // Declare accessor
  void Day(int day); // Declare mutator
  int Month() const { return month_; } // Declare accessor
  void Month(int month); // Declare mutator
  int Year() const { return year_; } // Declare accessor
  void Year(int year); // Declare mutator

private:
  bool LeapYear(int year) const; // Declare function
  int DaysInMonth(int month, int year) const; // Declare function
  int day_{1}; // Declare member variable
  int month_{1}; // Declare member variable
  int year_{0}; // Declare member variable
};

Date::Date(int day, int month, int year) { // Constructor definition
  Year(year); // Set member variable through mutator
  Month(month); // Set member variable through mutator
  Day(day); // Set member variable through mutator
}

bool Date::LeapYear(int year) const { // Define function
    if(year % 4 != 0)
        return false;
    else if(year % 100 != 0)
        return true;
    else if(year % 400 != 0)
        return false;
    else
        return true;
}

int Date::DaysInMonth(int month, int year) const { // Define function
    if(month == 2)
        return LeapYear(year) ? 29 : 28;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

void Date::Day(int day) { // Define mutator and invariants
  if (day >= 1 && day <= DaysInMonth(Month(), Year())) // Pass in the accessors as arguments for posterity
    day_ = day;
}

void Date::Month(int month) { // Define mutator and invariants
  if (month >= 1 && month <= 12)
    month_ = month;
}

void Date::Year(int year) { year_ = year; } // Define mutator and invariants (no invariant for year)

// Test
int main() {
  Date date(29, 2, 2016);
  assert(date.Day() == 29);
  assert(date.Month() == 2);
  assert(date.Year() == 2016);
    
  Date date2(29, 2, 2019);
  assert(date2.Day() != 29);
  assert(date2.Month() == 2);
  assert(date2.Year() == 2019);
}