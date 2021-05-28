#include <iostream>
#include "../include/Person.hpp"

int main() {
    Person* person = new Person("John Doe");
    std::cout << person << std::endl;

    return 0;
}