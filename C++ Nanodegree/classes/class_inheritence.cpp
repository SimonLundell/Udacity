#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    int doors = 0;
    string color = "blue";
    
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels and " << doors << " doors\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
    bool kickstand = true;
};

class Truck : public Vehicle {
public:
    bool trailer = true;  
};

int main() 
{
    Car car;
    car.wheels = 4;
    car.doors = 4;
    car.sunroof = true;
    car.Print();
    if(car.sunroof)
        std::cout << "And a sunroof!\n";
    
    Truck truck;
    truck.color = "black";
    truck.wheels = 8;
    truck.doors = 2;
    truck.Print();
    if (truck.trailer)
        std::cout << "A trailer is connected!\n";
};