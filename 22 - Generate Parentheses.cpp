#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(const int& __N) {
    if (__N == 0) {
      return {""};
    }
    vector<string> RES;
    for (int A = 0; A < __N; ++A) {
      for (auto L : this->generateParenthesis(A)) {
        for (auto R : this->generateParenthesis(__N - A - 1)) {
          RES.push_back("(" + L + ")" + R);
        }
      }
    }
    return RES;
  }
};
