#include <bits/stdc++.h>
#define ASCII_SHIFT 48
using namespace std;

class Solution {
 private:
  enum VAL_SIGN { POSITIVE = 1, NEGITIVE = -1 };
  enum OP_SIGN { NO_SIGN, TIMES, DIVIDE };

 public:
  int calculate(string s) {
    stack<int> STACK;
    VAL_SIGN SIGN = VAL_SIGN::POSITIVE;
    OP_SIGN OP = OP_SIGN::NO_SIGN;
    int VAL;
    for (auto i = s.begin(); i != s.end(); ++i) {
      if (*i == ' ') {
        continue;
      }
      if (isdigit(*i)) {
        VAL = *i - ASCII_SHIFT;
        for (++i; i != s.end() && isdigit(*i); ++i) {
          VAL = VAL * 10 + (*i - ASCII_SHIFT);
        }
        --i;
        if (OP == OP_SIGN::TIMES) {
          int R = STACK.top() * VAL;
          STACK.pop();
          STACK.push(R);
          OP = OP_SIGN::NO_SIGN;
        } else if (OP == OP_SIGN::DIVIDE) {
          int R = STACK.top() / VAL;
          STACK.pop();
          STACK.push(R);
          OP = OP_SIGN::NO_SIGN;
        } else {
          STACK.push(VAL * SIGN);
        }
      } else if (*i == '+') {
        SIGN = VAL_SIGN::POSITIVE;
      } else if (*i == '-') {
        SIGN = VAL_SIGN::NEGITIVE;
      } else if (*i == '*') {
        OP = OP_SIGN::TIMES;
      } else if (*i == '/') {
        OP = OP_SIGN::DIVIDE;
      }
    }
    int RESULT = 0;
    while (!STACK.empty()) {
      RESULT += STACK.top();
      STACK.pop();
    }
    return RESULT;
  }
};
