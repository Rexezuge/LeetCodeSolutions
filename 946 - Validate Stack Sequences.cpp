#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static bool validateStackSequences(const vector<int>& pushed,
                                     const vector<int>& popped) noexcept {
    // Variable Initialization
    vector<int> validateStack;
    int numPoped = 0;

    // Perform the Algorithm
    for (const int i : pushed) {
      validateStack.push_back(i);
      while (!validateStack.empty() && validateStack.back() == popped[numPoped])
        validateStack.pop_back(), ++numPoped;
    }

    // Runtime O(N)
    // Space O(N)
    return validateStack.empty();
  }
};
