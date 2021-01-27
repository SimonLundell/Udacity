#include <iostream>

// Primary usecase of lvalue-references is pass-by-reference in function calls
void myFunction(int &val)
{
    ++val;
}

int main()
{
    int i = 1; 
    myFunction(i);

    std::cout << "i = " << i << std::endl;

    return 0;
}