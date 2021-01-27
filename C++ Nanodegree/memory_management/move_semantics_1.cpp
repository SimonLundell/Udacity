#include <iostream>
// myFunction cant take an lvalue as an argument when defined as rvalue-reference
// we can however create an lvalue and pass it to myFunction as std::move(i), since move converts lvalue to rvalue
void myFunction(int &&val) // by passing this as an rvalue-reference, we are telling the function that the input argument is yours, caller (main)
                            // doesnt need that object anymore (it is deleted)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    myFunction(42);

    return 0; 
}

/*
rvalue-references are themselves lvalues. In example above val is an lvalue because it is given access to the memory location where 42 is stored.

*/