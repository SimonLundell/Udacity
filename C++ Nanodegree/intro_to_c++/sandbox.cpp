#include <bits/stdc++.h>
#include <iostream>
using namespace std; 

int main() {
    string value = "5.8.2-Linux";
    value.erase(value.begin()+3, value.end());

    std::cout << value << "\n";
}