#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<int, std::string> test = {{1,"Hello"},{2,"Goodbye"}};

    std::cout << test[1] << "\n";
    std::cout << test[2] << "\n";
    std::cout << test.count(1) << "\n";
    test[1] = "Hello";
    std::cout << test.count(1) << "\n";

    for (auto const &i : test) std::cout << i.first << " " << i.second << "\n";

    std::unordered_map<std::string, int> test2{{"Test1", 1}, {"Test2",2}};
    for (auto const &j : test2) std::cout << j.first << " " << j.second << "\n";

    test2["Test1"] += 1;
    test2["Test2"] += 2;

    for (auto const &j : test2) std::cout << j.first << " " << j.second << "\n";

}