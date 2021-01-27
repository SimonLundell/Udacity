#include <iostream>

int main()
{
    int i = 1; // lvalue i, rvalue 1
    int j = 2;  // lvalue j, rvalue 2
    int k = i + j; // an rvalue i+j is created temporarily, then copied into the address of lvalue k
    int &&l = i + j; // && "rvalue-reference (since C++11)" i+j is directly put in the adress of l without the copying of line above

    std::cout << "k = " << k << ", l = " << l << std::endl;

    return 0; 
}