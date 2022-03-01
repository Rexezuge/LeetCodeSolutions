#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<int> countBits(int n) noexcept {
    // Variable Initialization
    vector<int> retVec(n + 1);

    // Perform the Algorithm
    for (int i = 0; i <= n; ++i) {
      int sum = 0, num = i;
      while (num > 0) sum += num % 2, num /= 2;
      retVec[i] = sum;
    }

    // Runtime O(NlogN)
    // Space O(N)
    return retVec;
  }
};
