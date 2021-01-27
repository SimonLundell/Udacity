#include <assert.h>
#include <string>
#include <iostream>

class Person { // Could just as well be a struct, no mutators.
    public:
    Person(std::string n) : name(n) {}; // List initializer. Declare variable in constructor, then call upon the defined member variable and assign it with n
    
    std::string name;
};

int main() {
    Person alice("Alice");
    Person simon("Simon");

    std::cout << alice.name << " " << simon.name << "\n";

    assert(alice.name != simon.name);

    return 0;
}