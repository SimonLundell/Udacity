#include <iostream>

using namespace std;

int main() {
    int a[4]{0,2,4,5}; // This is to declare an array of length 4 (4 elements), and assigning values to them. dont confuse with vectors!

    for (auto i : a) {
        cout << i << " ";
    }
}