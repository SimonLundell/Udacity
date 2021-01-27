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
    MyMovableClass(MyMovableClass &&source) // 4 : move constructor
    {
        std::cout << "MOVING (c’tor) instance " << &source << " to instance " << this << std::endl;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
    }
    MyMovableClass &operator=(MyMovableClass &&source) // 5 : move assignment operator
    {
        std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;

        delete[] _data;

        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }
};

MyMovableClass createObject(int size) {
    MyMovableClass obj(size); // regular constructor
    return obj; // return MyMovableClass object by value
}

int main() {
    MyMovableClass obj1(10); // regular constructor
    MyMovableClass obj2(obj1); // copy constructor
    obj2 = obj1; // copy assignment operator

    return 0;
}

/*
A special call to copy constructor
Try compiling and then running the rule_of_three.cpp to notice that MyMovableClass obj4 = createObject(10); 
would not print the cout statement of copy constructor on the console. 
This is because the copy constructor is called on the temporary object.
*/