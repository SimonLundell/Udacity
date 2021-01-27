#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int j = 42;
    myFunction(j);

    //myFunction(42); compiler error. rvalue (42) can be passed as an argument since 42 = &val is not a valid statement

    int k = 23; 
    //myFunction(j+k); // compiler error. Even though j and k are lvalues, performing the + operation computes an rvalue.

    return 0; 
}