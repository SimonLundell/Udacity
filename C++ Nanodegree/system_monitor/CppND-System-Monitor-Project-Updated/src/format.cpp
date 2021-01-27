#include <string>

#include "format.h"

using std::string;
using std::to_string;

string Format::ElapsedTime(long seconds) {
  string result;
  string h = to_string(seconds / 3600);
  string m = to_string((seconds % 3600) / 60);
  string s = to_string(seconds % 60);
  string hh;
  if (h.length() > 2) {
    hh = string(3 - h.length(), '0') + h;
  } else {
    hh = string(2 - h.length(), '0') + h;
  }
  string mm = string(2 - m.length(), '0') + m;
  string ss = string(2 - s.length(), '0') + s;
  result = hh + ':' + mm + ":" + ss;
  return result;
}