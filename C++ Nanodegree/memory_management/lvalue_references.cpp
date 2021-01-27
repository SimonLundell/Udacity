#include <iostream>

int main()
{
    int i = 1; 
    int &j = i; // lvalue is a reference to i.
    ++i;
    ++j;

    std::cout << "i = " << i << ", j = " << j << std::endl;

    return 0;
}