#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    bool NEGITIVE = false;
    for (const auto& i : s)
      if (i == '-') {
        NEGITIVE = !NEGITIVE;
        break;
      }
    try {
      return stoi(s);
    } catch (invalid_argument&) {
      return 0;
    } catch (out_of_range&) {
      return NEGITIVE ? INT_MIN : INT_MAX;
    }
  }
};
