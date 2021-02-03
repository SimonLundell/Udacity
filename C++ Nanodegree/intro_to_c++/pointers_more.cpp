//When using pointers with functions, some care should be taken. If a pointer is passed to a function and then assigned to a variable in the function that goes out of scope after the function finishes executing, 
//then the pointer will have undefined behavior at that point - the memory it is pointing to might be overwritten by other parts of the program.

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void addone(vector<int> *c) { // passing a reference
    (*c).push_back(4); // dereferencing c to get variable stored at address. Add one value to that variable.
}

int main() {
    vector<int> v {1, 2, 3};

    vector<int> *k = &v; //important that pointer is of same type as the variable it is pointing to!

    for (int a: v) {
        cout << a << "\n";
    }
    
    addone(k); // calling the function addone that will add one value to the variable that is stored in the address which k is pointing to

    cout << (*k)[0] << "\n"; //in vectors, () is important when de-referencing

    for (int j: v) {
        cout << j << " ";
    }
    cout << "\n";
}