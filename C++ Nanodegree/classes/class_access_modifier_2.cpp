#include <string>
#include <iostream>

// Define base class Animal
class Animal {
  public:
    std::string color = "Undecided";
    std::string name = "Not available";
    int age = 0;
    
    void Print() const {std::cout << "This animals name is " << name << 
        " and its color is " << color << ", he is " << age << " years old\n";}
    
};

// Declared derived private class Snake. Accessors / mutators required for reading/writing variables in Animal
class Snake : private Animal {
    public:
    int length = 100;
    void Name(std::string n) { name = n; } // Function name and variable name can not be same (Name and name. True for all)
    void Color(std::string c) { color = c;}
    void Age(int a) { age = a; }
    void print() { Print(); } // Calling a function with a function is OK!
    void MakeSound() const {std::cout << "Hsssss\n";}
};

// Declare derived protected class Cat. Accessors / mutators required for reading/writing variables in Animal
class Cat : protected Animal {
    public:
    int height = 30;
    void Name(std::string n) { name = n; }
    void Color(std::string c) { color = c;}
    void Age(int a) { age = a; }
    void print() { Print(); }
    void MakeSound() const {std::cout << "Mjaaooo\n";}
};

// Test in main()
int main() {
    Snake snake;
    snake.Color("green");
    snake.Name("Pablo");
    snake.Age(45);
    snake.length = 100;
    snake.print();
    snake.MakeSound();
    
    Cat cat;
    cat.Color("white");
    cat.Name("Tindra");
    cat.Age(10);
    cat.height = 30;
    cat.print();
    cat.MakeSound();
    
}