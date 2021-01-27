#include <iostream>

//TODO Practice writing switch statements
// Don't forget an include statement if you want to use std::cout

int main() {
    
    // TODO: write a program that outputs whether a vehicle is a motorcycle,
    // 2-door coupe, 4-door car or a 5-door mini-van. 
    // You should create a variable that holds the number of doors in the vehicle
    // A motorcycle would have doors = 0 for example. 
    // Then use a switch statement to output to the terminal the kind of vehicle
    // you have
    
    int doors = 5;
    
    switch(doors)
    {
        case 0:
            std::cout << "tis a motorcycle" << std::endl;
            break;
        case 2:
            std::cout << "tis a 2-door coupe" << std::endl;
            break;
        case 4:
            std::cout << "tis a 4-door car" << std::endl;
            break;
        case 5:
            std::cout << "tis a 5-door minivan" << std::endl;
            break;
    }
    
    std::cout << "Your vehicle has " << doors << " number of doors" << std::endl;
    
    return 0;
}
