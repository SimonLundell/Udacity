#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
    MyMovableClass(const MyMovableClass &source) { // copy constructor. We pass const to ensure we dont modify the source
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    MyMovableClass &operator=(const MyMovableClass &source) { // = operator overloading
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source) // boilerplate code when overloading the equal-sign
            return *this;
        delete[] _data;
        *_data = *source._data;
        _size = source._size;
        return *this;
    }
};

MyMovableClass createObject(int size) {
    MyMovableClass obj(size); // regular constructor
    return obj; // return MyMovableClass object by value
}

int main() {
    MyMovableClass obj1(10);
    MyMovableClass obj2(obj1);
    obj2 = obj1;
    
    MyMovableClass obj3 = obj1;
    // Here, we are instantiating obj3 in the same statement; hence the copy assignment operator would not be called.
    // MyMovableClass obj4 = createObject(10); //Delete obj 4 below to run
    // createObject(10) returns a temporary copy of the object as an rvalue, which is passed to the copy constructor.
    
    MyMovableClass obj4(createObject(10)); //Alternative way.

    obj4 = createObject(10); // call to copy assignment operator

    return 0;
}

/*
A special call to copy constructor
Try compiling and then running the rule_of_three.cpp to notice that MyMovableClass obj4 = createObject(10); 
would not print the cout statement of copy constructor on the console. 
This is because the copy constructor is called on the temporary object.
*/