#include <string>
#include <cstring>
#include <iostream>

class Car {
    // Naming convention to have "_" before variable in private variables
    private:
        std::string _brand;
        
    // 
    public:
        void brand(char*); // Define setter as accepting a pointer to a character (character array)
        std::string brand() const; // Making getter const
        
};

// Define setters
void Car::brand(char* brand)
{
    Car::_brand = brand;
}

// Define getters
std::string Car::brand() const
{
    return _brand;
}

// Test in main()
int main() 
{
    Car car;
    char brand[] = "Peugeot"; //C-style character-array. Requires access by a pointer
    car.brand(brand);
    std::cout << car.brand() << "\n";   
}