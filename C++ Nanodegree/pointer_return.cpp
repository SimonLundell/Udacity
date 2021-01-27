#include <iostream>
using std::cout;

int* AddOne(int& j) 
{
    // Increment the referenced int and return the
    // address of j.
    j++;
    return &j; // has to return a reference since the pointer to be returned is only valid if pointing to a reference
}

int main() 
{
    int i = 1;
    cout << "The value of i is: " << i << "\n";
    
    // Declare a pointer and initialize to the value
    // returned by AddOne:
    int* my_pointer = AddOne(i); // my_pointer will only be a pointer if addone is a pointer, since it is an assignment of my_pointer to a function
    cout << "The value of i is now: " << i << "\n";
    cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << "\n";
}