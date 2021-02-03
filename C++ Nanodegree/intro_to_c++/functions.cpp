#include <iostream>
#include <vector>
#include <numeric> // part of the standard library

using namespace std;

int vectorMult(const vector<int> &v) { // Using a reference to v so we dont copy it. Make it constant so we cant modify it
    int sum = 0;
    for (const int &i : v) { // same as above
        sum += i;
    }
    return sum;
}

int main() {
    vector<int> v{1,2,3,4,5};
    cout << vectorMult(v) << "\n";

    cout << accumulate(v.begin(), v.end(), 0) << "\n"; // Using the numeric library we can use the accumulate function.
}