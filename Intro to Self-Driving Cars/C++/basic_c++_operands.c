#include <iostream>

int main() {
    
    // TODO: define two floating point numbers. Assign 12.07 to the
    // first floating point number. Assign 65.102 to the 
    // second floating point number.
    float val1 = 12.07;
    float val2 = 65.102;
    
    // TODO: Calculate the sum of the two floating point variables into
    // the float_sum variable.
    
    float float_sum = val1 + val2;
    
    std::cout << float_sum << std::endl;
    
    // TODO: Calculate difference between the second and first number
    // output the results to cout. 
    
    float dif = val2 - val1;
    
    std::cout << dif << std::endl;
    
    // TODO: Calculate second_float / first_float and output the results
    // to cout.
    
    float div = val2 / val1;
    
    std::cout << div << std::endl;
    
    // TODO: Calculate the product of the two numbers and output the results
    // to cout.
    
    float prod = val1 * val2;
    
    std::cout << prod << std::endl;

    return 0;
}
