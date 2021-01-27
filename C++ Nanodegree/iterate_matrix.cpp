#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
  vector<vector<int>> b{{1, 2}, {3, 4}, {5, 6}};

  // could use auto instead of vector<int>
  for (vector<int> i : b) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}