#include <assert.h>
#include <string>

struct Person {
public:
  // Initializing a reference or a const can only be done in initilization lists
  Person(std::string const & n) : name(n) {}
  
  std::string const name;
};

// Test
int main() {
  Person alice("Alice");
  Person bob("Bob");
  assert(alice.name != bob.name);
}