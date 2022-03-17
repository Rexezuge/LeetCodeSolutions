#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int scoreOfParentheses(string_view s) noexcept {
    // Variable Initialization
    stack<int> scoreStack;

    // Setup the Variable
    scoreStack.push(0);

    // Perform the Algorithm
    for (char c : s) {
      switch (c) {
        case '(':
          scoreStack.push(0);
          break;
        case ')':
          int scoreA = scoreStack.top();
          scoreStack.pop();
          int scoreB = scoreStack.top();
          scoreStack.pop();
          scoreStack.push(scoreB + max(1, scoreA << 1));
          break;
      };
    }

    // Runtime O(N)
    // Space O(N)
    return scoreStack.top();
  }
};
