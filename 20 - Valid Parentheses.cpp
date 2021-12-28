#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValid(string &STR) {
    reverse(STR.begin(), STR.end());
    stack<char> _S;
    while (!STR.empty()) {
      const auto &_T = STR.back();
      if (_T == '(' || _T == '{' || _T == '[') {
        _S.push(_T);
        STR.pop_back();
      } else {
        if (_S.empty()) {
          return false;
        }
        if (_T == ')' && _S.top() == '(') {
          _S.pop();
          STR.pop_back();
        } else if (_T == ']' && _S.top() == '[') {
          _S.pop();
          STR.pop_back();
        } else if (_T == '}' && _S.top() == '{') {
          _S.pop();
          STR.pop_back();
        } else {
          return false;
        }
      }
    }
    return _S.size() == 0 ? true : false;
  }
};
