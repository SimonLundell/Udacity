#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};

string CellString(State s) {
  string res;
  switch (s) {
    case State::kEmpty : res = "0   ";
      break;
    case State::kObstacle : res = "⛰️   ";
      break;
  }
  return res;
}

/* ALTERNATIVE CellString function.
string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}
*/

vector<int> ParseLine(string line) {
  int n;
  char c;
  vector<int> row;
  istringstream sline(line);

  while (sline >> n >> c && c == ',') {
    row.push_back(n);
  }
  return row;
}

vector<vector<int>> ReadBoardFile(string path) {
  vector<vector<int>> eBoard;
  ifstream myfile(path);

  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      eBoard.push_back(ParseLine(line));
    }
  }
  return eBoard;
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  vector<vector<int>> board = ReadBoardFile("1.board");
  PrintBoard(board);
}