// Include iostream for output
#include <cassert>
#include <iostream>

// Instantiating to avoid empty variables. Set initially to Jan 1st 2000
struct Date {
  int day{1}; // = 29; <- Also OK
  int month{1}; // = 8;
  int year{2000}; // = 1981;
};

// Define a main function to instantiate and test 
int main()
{
    Date date;
    
    // TODO: Initialize date to August 29, 1981
    date.day = 29;
    date.month = 8;
    date.year = 1981;
    
    // TEST
    assert(date.day == 29);
    assert(date.month == 8);
    assert(date.year == 1981);

    // Print the data in the structure
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
}