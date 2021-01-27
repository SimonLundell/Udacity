//TODO: Write a function that receives two integer matrices and outputs
// the sum of the two matrices. Then in your main() function, input a few
// examples to check your solution. Output the results of your function to 
// cout. You could even write a separate function that prints an arbitrarily 
// sized matric to cout.

#include <iostream>
#include <vector>

using namespace std;

vector < vector<int> >multiplication(vector < vector<int> > m1, vector < vector<int> > m2);

int main() {

    vector < vector<int> > matrix1(5, vector<int> (3, 5));
    vector < vector<int> > matrix2(5, vector<int> (3, 7));
    vector < vector<int> > matrixproduct; //(5, vector<int> (matrix1[0]));

    cout << "Matrix 1 is: " << '\n';
    
    for (int row = 0; row < matrix1.size(); row++) {
        for (int col = 0; col < matrix1[0].size(); col++) {
            cout << matrix1[row][col] << " ";
        }
    
        cout << endl;
    }
    
    cout << "Matrix 2 is: " << '\n';
    
    for (int row = 0; row < matrix2.size(); row++) {
        for (int col = 0; col < matrix2[0].size(); col++) {
            cout << matrix2[row][col] << " ";
        }
    
        cout << endl;
    }
    
    matrixproduct = multiplication(matrix1, matrix2);
    
    cout << "The product of the 2 matrices are: " << '\n';
    
    for (int row = 0; row < matrixproduct.size(); row++) {
        for (int col = 0; col < matrixproduct[0].size(); col++) {
            cout << matrixproduct[row][col] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
    
}

vector < vector<int> > multiplication(vector < vector<int> > m1, vector < vector<int> > m2) {
    
    vector < vector<int> > matrix3(m1.size(), vector<int> (m1[0]));
    
    for (int row = 0; row < m1.size(); row++) {
        for (int col = 0; col < m1[0].size(); col++) {
            matrix3[row][col] = m1[row][col] * m2[row][col];
        }
    }
    
    return matrix3;
}
