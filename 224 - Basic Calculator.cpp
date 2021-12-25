#include <bits/stdc++.h>
#define ASCII_SHIFT 48
using namespace std;

class Solution {
 private:
  enum VAL_SIGN { POSITIVE = 1, NEGITIVE = -1 };
  using P = pair<int, VAL_SIGN>;

 public:
  int calculate(string s) {
    stack<P> STACK;
    int SUM = 0, VAL = 0;
    VAL_SIGN SIGN = VAL_SIGN::POSITIVE;
    for (auto i = s.begin(); i != s.end(); ++i) {
      if (*i == ' ') {
        continue;
      }
      if (isdigit(*i)) {
        VAL = *i - ASCII_SHIFT;
        ++i;
        for (; i != s.end() && isdigit(*i); ++i) {
          VAL = VAL * 10 + (*i - ASCII_SHIFT);
        }
        --i;
        SUM += VAL * SIGN;
        SIGN = VAL_SIGN::POSITIVE;
      } else if (*i == '+') {
        SIGN = VAL_SIGN::POSITIVE;
      } else if (*i == '-') {
        SIGN = VAL_SIGN::NEGITIVE;
      } else if (*i == '(') {
        STACK.push(P(SUM, SIGN));
        SUM = 0;
        SIGN = VAL_SIGN::POSITIVE;
      } else if (*i == ')') {
        auto R = STACK.top();
        STACK.pop();
        SUM = R.first + SUM*R.second;
      }
    }
    return SUM;
  }
};
