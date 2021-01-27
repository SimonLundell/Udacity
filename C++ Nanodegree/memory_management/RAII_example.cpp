#include <stdlib.h>
#include <iostream>

class MyInt
{
    int *_p; // pointer to heap data
public:
    MyInt(int *p = NULL) { _p = p; } // Allocating memory in constructor
    ~MyInt() 
    { 
        std::cout << "resource " << *_p << " deallocated" << std::endl; 
        delete _p; // Deallocating in destructor
    }
    int &operator*() { return *_p; } // // overload dereferencing operator
};

int main()
{
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t I = 0; I < 5; ++I)
    {
        // allocate the resource on the stack
        MyInt en(new int(I));
        // MyInt *en = new MyInt(new int(i)); If we use this line, the destructor i MyInt would never be called, and we'd have a memory leak.

        // use the resource
        std::cout << *en << "/" << den[I] << " = " << *en / den[I] << std::endl;
    }

    return 0;
}