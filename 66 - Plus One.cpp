#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<int> plusOne(vector<int>& digits) noexcept {
    // Variable Initialization
    int i = digits.size() - 1;

    // Simple Plus One Case
    if (digits[i] != 9) {
      ++digits[i];
      return digits;
    }

    // Digits Overflow Case
    do {
      digits[i] = 0;
    } while (--i >= 0 && digits[i] == 9);
    if (i < 0)
      digits.insert(digits.begin(), 1);
    else
      ++digits[i];

    // Runtime O(N)
    // Space O(1)
    return digits;
  }
};
