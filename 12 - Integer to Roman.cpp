#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string intToRoman(int &num) {
    vector<uint16_t> INTEGER = {1000, 900, 500, 400, 100, 90, 50,
                                40,   10,  9,   5,   4,   1};
    vector<string> ROMAN = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                            "XL", "X",  "IX", "V",  "IV", "I"};
    string RESULT;
    for (size_t i = 0; num > 0; ++i) {
      while (num >= INTEGER[i]) {
        RESULT += ROMAN[i];
        num -= INTEGER[i];
      }
    }
    return RESULT;
  }
};
