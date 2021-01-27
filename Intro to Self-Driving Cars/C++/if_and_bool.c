#include <iostream>

int main() {
    
    /* 
    * TODO: Use this as a playground for writing if, else if and else statements
    * To get you started here, are some ideas:
    * 
    * 1. Create an integer variable and a set of if, elseif and else statements that
    * output whether the number is positive or negative.
    * 
    * 2. Create a character variable containing 'a' for acceleration, 'b' for braking, 
    * 'p' for parked, or 'n' for neutral and outputs whether or not the vehicle is accelerating, braking, 
    * parked or in neutral.
    *
    * Practice Using Boolean Logic
    *
    * You can see an example solution in the solution.cpp file
    */
    int num = 2;
    
    if (num < 0)
    {
        std::cout << "Number is negative" << std::endl;
    }
    
    else if (num == 0)
    {
        std::cout << "Number is 0" << std::endl;
    }
    
    else
    {
        std::cout << "Number is positive" << std::endl;
    }
    
    char car_status = 'n';
    
    if (car_status == 'a')
    {
        std::cout << "Car is accelerating" << std::endl;
    }
    
    else if (car_status == 'b')
    {
        std::cout << "Car is braking" << std::endl;
    }
    
    else if (car_status == 'p')
    {
        std::cout << "Car is parked" << std::endl;
    }
    
    else
    {
        std::cout << "Car is in neutral" << std::endl;
    }
    
    
    return 0;
}

