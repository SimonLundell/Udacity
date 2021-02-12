#include <bits/stdc++.h>
#include <iostream>
using namespace std; 

int main() {
    std::clock_t start = std::clock();
    std::default_random_engine generator;
    //double random = rand() % 4 + 2;
    std::uniform_int_distribution<int> distribution(4,6);
    int random = distribution(generator);
    while (true) {
       if ( ((std::clock() - start) / CLOCKS_PER_SEC) >= random) {
           std::cout << random << std::endl;
           start = std::clock();
           std::cout << std::clock() << std::endl;
           random = distribution(generator);
       }
    }
}