#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string convert(string& s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    vector<vector<char>> VEC(numRows);
    for (auto& i : VEC) {
      i = vector<char>(s.size() / 2 + 1);
    }
    reverse(s.begin(), s.end());
    bool REVERSE = false;
    int CURR = 0;
    int SHIFT = 0;
    while (!s.empty()) {
      VEC[CURR][SHIFT] = s.back();
      s.pop_back();
      if (!REVERSE) {
        ++CURR;
      } else {
        --CURR;
        ++SHIFT;
      }
      if (CURR + 1 >= numRows || CURR <= 0) {
        REVERSE = !REVERSE;
      }
    }
    string RESULT;
    RESULT.reserve(s.size());
    for (const auto& R : VEC) {
      for (const auto& C : R) {
        if (C) {
          RESULT.push_back(C);
        }
      }
    }
    return RESULT;
  }
};
