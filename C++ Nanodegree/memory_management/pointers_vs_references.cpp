#include <iostream>

void AddFour(int &val) // By reference, val is modified.
{
    val += 4;
}

void AddSix(int *val) // pointing to the address of val.
{
    *val += 6; // de-referencing to get the value in address of val and adding 6 to that value.
}

int main()
{
    int val = 0;
    AddFour(val); // Here we might accidentally modify val, if we are not aware that the function definition refers to val by reference
    AddSix(&val); // Here we have to explicitly state that we will use val as a reference, it is safer but more complex.

    std::cout << "val = " << val << std::endl;
 
    return 0;
}

/*
    Pointers can be declared without initialization. 
    This means we can pass an uninitialized pointer to a function who then internally performs the initialization for us.

    Pointers can be reassigned to another memory block on the heap.

    References are usually easier to use (depending on the expertise level of the programmer). 
    Sometimes however, if a third-party function is used without properly looking at the parameter definition, 
    it might go unnoticed that a value has been modified.

*/