#include <iostream>

void AddThree(int *val) // Pointing to the value stored in the address of val. *val is a copy of the address that val is contained in.
{
    *val += 3; // Adding 3 to the value stored at the address that val is pointing to by dereferencing it (* at left side of =)
}

int main()
{
    int val = 0;
    AddThree(&val); // Calling the function with the reference (address) to val as argument
    val += 2;

    std::cout << "val = " << val << std::endl;
 
    return 0;
}