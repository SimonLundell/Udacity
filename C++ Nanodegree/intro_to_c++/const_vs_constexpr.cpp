#include <iostream>

int main()
{
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    const int j = i * 2;  // "j can only be evaluated at run time."
                          // "But I promise not to change it after it is initialized."
    
    constexpr int k = 3;  // "k, in contrast, can be evaluated at compile time."
                          // Add k = 3 + 1 and the program will fail to compile
    
    std::cout << "j = " << j << "\n";
    std::cout << "k = " << k << "\n";
}