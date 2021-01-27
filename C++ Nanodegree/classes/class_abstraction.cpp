#include <cassert>
#include <string>
#include <vector>

class Date {
 public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);
  std::string String() const;

 private:
  bool LeapYear(int year) const;
  int DaysInMonth(int month, int year) const;
  int day_{1};
  int month_{1};
  int year_{0};
};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

bool Date::LeapYear(int year) const {
  if (year % 4 != 0)
    return false;
  else if (year % 100 != 0)
    return true;
  else if (year % 400 != 0)
    return false;
  else
    return true;
}

int Date::DaysInMonth(int month, int year) const {
  if (month == 2)
    return LeapYear(year) ? 29 : 28;
  else if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  else
    return 31;
}

void Date::Day(int day) {
  if (day >= 1 && day <= DaysInMonth(Month(), Year())) day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12) month_ = month;
}

void Date::Year(int year) {
  year_ = year;
}
// Implemented such that the user doesnt care about how it is done, just that he can call date.String() and it will show the string conversion of the int types.
std::string Date::String() const {
    std::string d = std::to_string(Day());
    std::string y = std::to_string(Year());
    switch(Month()) {
        case 1:
            return "January " + d + ", " + y;
        case 2:
            return "February " + d + ", " + y;
        case 3:
            return "March " + d + ", " + y;
        case 4:
            return "April " + d + ", " + y;
        case 5:
            return "May " + d + ", " + y;
        case 6:
            return "June " + d + ", " + y;
        case 7:
            return "July " + d + ", " + y;
        case 8:
            return "August " + d + ", " + y;
        case 9:
            return "September " + d + ", " + y;
        case 10:
            return "October " + d + ", " + y;
        case 11:
            return "November " + d + ", " + y;
        case 12:
            return "December " + d + ", " + y;
    }
}

// Test
int main() {
  Date date(29, 8, 1981);
  assert(date.String() == "August 29, 1981");
}