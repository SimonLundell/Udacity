#include <cassert>

class Date {
 public:
  Date(int day, int month, int year);
  int Day() { return day; }
  void Day(int day);
  int Month() { return month; }
  void Month(int month);
  int Year() { return year; }
  void Year(int year);

 private:
  int day{1};
  int month{1};
  int year{0};
};

Date::Date(int d, int m, int y){
    Day(d);
    Month(m);
    Year(y);
}

// Notice the declaration here matches the definition except for the scope identifier ("::")
void Date::Day(int day) {
    if(day >= 1 && day <= 31)
        Date::day = day; // Scope identifier shows that we sign class Date variable day to the "naked" day in the definition
}

void Date::Month(int month) {
    if(month >= 1 && month <= 12)
        Date::month = month;
}

void Date::Year(int year) { Date::year = year; }

int main() {
  Date date(29, 8, 1981); //When constructor is made, class has to be called with the arguments in constructor
  
  //date.Day(29);
  //date.Month(8);
  //date.Year(1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
}