#include <assert.h>
#include <string>
#include <sstream>

// Declare template to take 2 inputs, both of which will be assigned to the types KeyType and ValueType.
// This means "age" and "20" will be assigned to each respectively
template <typename KeyType, typename ValueType>
class Mapping {
public:
  Mapping(KeyType key, ValueType value) : key(key), value(value) {} // constructor taking the new types and assigning them to the values defined below.
  std::string Print() const {
    std::ostringstream stream;
    stream << key << ": " << value;
    return stream.str();
  }
  KeyType key;
  ValueType value;
};

// Test
int main() {
  Mapping<std::string, int> mapping("age", 20);
  assert(mapping.Print() == "age: 20");
}