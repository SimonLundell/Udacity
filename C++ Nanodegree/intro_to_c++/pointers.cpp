#include <iostream>
#include <vector>

//A pointer will know what address and type it shall point to at compile-time

using namespace std;

int main() {
    int k = 5;
    int &j = k;
    int* p_k = &k;

    cout << "k is " << k << "\n"; // just the value k
    cout << "pointer to k is " << p_k << "\n"; // p_k defined as a pointer to the address where k is stored
    cout << "&k " << &k << "\n"; // again, the address where k is stored, "reference"
    cout << "*p_k " << *p_k << "\n";   // dereferencing p_k, "pointing to what is stored in the address that p_k is pointing to"
    cout << "j " << j << "\n"; // j is a reference to k, meaning j is just another name for k
    cout << "++j " << ++j << "\n"; // incrementing j (or you could say incrementing k)
    
}