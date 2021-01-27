#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void ParseVec(string s) {
    int n;
    char c;
    vector<int> res;

    istringstream stream(s);

    while (stream >> n >> c) {
        res.push_back(n);
    }

    for (auto& i : res) {
        cout << i << " ";
    }
}

int main() {
    std::ifstream my_file;
    my_file.open("files/l.board");
    if (my_file) {
        std::cout << "The file stream has been created!" << "\n";
        std::string line;
        while (getline(my_file, line)) {
            ParseVec(line);
            std::cout << line << "\n";
        }
    }
}