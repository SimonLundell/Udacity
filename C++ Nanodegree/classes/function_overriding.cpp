#include <assert.h>
#include <string>

class Animal {
public:
  virtual std::string Talk() const = 0;
};

class Dog : public Animal {
  public:
    std::string Talk() const override; // Override here provides some compiler protection, compiler will complain if we forget to inherit from Animal.
};

std::string Dog::Talk() const {
    return "Woof";
}

int main() {
  Dog dog;
  assert(dog.Talk() == "Woof");
}