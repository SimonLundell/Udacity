#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main() 
{
    string b("1,2,3p");

    istringstream my_stream(b);

    char c;
    int n;

    while (my_stream >> n >> c) { // This condition needs both n and c to be fed a character of correct type, otherwise it returns false
      cout << "That stream was successful:" << n << " " << c << "\n";
    }
    cout << "The stream has failed." << "\n";
}