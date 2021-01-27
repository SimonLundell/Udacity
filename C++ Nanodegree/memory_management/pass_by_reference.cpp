#include <iostream>

void AddFour(int &val) // val is a reference to the argument in the function call below marked "Here!"
{
    val += 4;
}

int main()
{
    int val = 0;
    AddFour(val); // Here!
    val += 2;

    std::cout << "val = " << val << std::endl;
 
    return 0;
}

/*
In addition to the possibility to directly exchange information between function and caller, 
passing variables by reference is also faster as no information needs to be copied, as well as more memory-efficient.

A major disadvantage is that the caller does not always know what will happen to the data it passes to a function 
(especially when the function code can not be modified easily). 
Thus, in some cases, special steps must be taken to protect ones data from inappropriate modification.
*/