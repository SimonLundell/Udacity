#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> mySharedPtr(new int);
    std::weak_ptr<int> myWeakPtr(mySharedPtr);

    mySharedPtr.reset(new int);

    if (myWeakPtr.expired() == true) // Checking if the memory pointed to is still valid.
    {
        std::cout << "Weak pointer expired!" << std::endl;
    }

    return 0;
}