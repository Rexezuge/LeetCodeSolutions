#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int romanToInt(string &s) {
    reverse(s.begin(), s.end());
    vector<uint16_t> INTEGER = {1000, 900, 500, 400, 100, 90, 50,
                                40,   10,  9,   5,   4,   1};
    vector<string> ROMAN = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                            "XL", "X",  "IX", "V",  "IV", "I"};
    size_t RESULT = 0;
    for (size_t i = 0; !s.empty();) {
      const char &S1 = s.back();
      const string &S2 =
          string(1, S1) + (s.size() >= 2 ? s[s.size() - 2] : '\0');
      if (S1 == ROMAN[i].front() && ROMAN[i].size() == 1) {
        RESULT += INTEGER[i];
        s.pop_back();
      } else if (S2 == ROMAN[++i]) {
        RESULT += INTEGER[i];
        s.pop_back();
        s.pop_back();
      }
    }
    return RESULT;
  }
};
