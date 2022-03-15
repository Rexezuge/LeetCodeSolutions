#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static string minRemoveToMakeValid(string s) {
    // Remove Extra Left Parentheses
    for (int i = 0, countParentheses = 0, __END = s.size(); i < __END; ++i) {
      switch (s[i]) {
        case '(':
          ++countParentheses;
          break;
        case ')':
          countParentheses == 0 ? s[i] = '#' : --countParentheses;
          break;
      }
    }

    // Remove Extra Right Parentheses
    for (int i = s.size() - 1, countParentheses = 0; i >= 0; --i) {
      switch (s[i]) {
        case ')':
          ++countParentheses;
          break;
        case '(':
          countParentheses == 0 ? s[i] = '#' : --countParentheses;
          break;
      }
    }

    // Construct Return String
    string retVal;
    for (int i = 0, __END = s.size(); i < __END; ++i)
      if (s[i] != '#') retVal.push_back(s[i]);

    // Runtime O(N)
    // Space O(1)
    return retVal;
  }
};
