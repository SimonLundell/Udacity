//TODO: Use this as a playground to practice with vectors
#include <iostream>
#include <vector>

using namespace std;

vector<int> subtraction(vector<int> v1, vector<int> v2);
vector<int> multiplication(vector<int> v1, vector<int> v2);


int main() {
    
    vector<int> vector1(3);
    
    vector1[0] = 5;
    vector1[1] = 10;
    vector1[2] = 27;
    
    cout << "Vector 1 is ";
    
    for (int i = 0; i < vector1.size(); i++) {
        cout << vector1[i] << " ";
    }
    
    cout << endl;
    
    vector<int> vector2(3);
    
    vector2[0] = 3;
    vector2[1] = 17;
    vector2[2] = 12;
    
    cout << "Vector 2 is ";
    
    for (int i = 0; i < vector2.size(); i++) {
        cout << vector2[i] << " ";
    }
    
    vector<int> v3 (vector1.size());
    
    v3 = subtraction(vector1, vector2);
    
    cout << '\n' << "The subtraction of the vectors are ";
    
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    
    cout << '\n' << "Multiplied they are: ";

    vector<int> v4 (vector1.size());

    v4 = multiplication(vector1, vector2);

    for (int i = 0; i < v4.size(); i++) {
	cout << v4[i] << " ";
    }
    
    cout << '\n';

    return 0;
}

vector<int> subtraction(vector<int> v1, vector<int> v2) {
    
    vector<int> vectorsum(v1.size());
    
    for (int i = 0; i < vectorsum.size(); i++) {
        vectorsum[i] = v1[i] - v2[i];
    }
    
    return vectorsum;
}

vector<int> multiplication(vector<int> v1, vector<int> v2) {
    
    vector<int> vectorsum(v1.size());
    
    for (int i = 0; i < vectorsum.size(); i++) {
        vectorsum[i] = v1[i] * v2[i];
    }
    
    return vectorsum;
}

//TODO:
// Fill out your program's header. The header should contain any necessary
// include statements and also function declarations


//TODO:
// Write your main program. Remember that all C++ programs need
// a main function. The most important part of your program goes
// inside the main function. 
