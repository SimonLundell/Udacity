#include <iostream>

// Since val and success are called as references, we can modify several values without having to handle several in a return statement
// which can be quite cumbersome.

void AddFive(int &val, bool &success) {
    val += 5;
    success = true;
}

int main()
{
    int val = 0;
    bool success = false;
    AddFive(val, success);
    val += 2;

    std::cout << "val = " << val << ", success = " << success << std::endl;
 
    return 0;
}