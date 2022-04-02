#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int rob(vector<int>& nums) noexcept {
    // Variable Initialization
    const int n = nums.size();
    int resultDP[n + 2];
    memset(resultDP, -1, sizeof resultDP);

    // Dynamic Programming Bottom Up
    const function<int(void)> runBottomUpDP = [&](void) {
      // Setup Base Case
      resultDP[0] = 0, resultDP[1] = 0;
      // Run Dynamic Programming
      for (int i = 0; i < n; ++i)
        resultDP[i + 2] = max(resultDP[i + 1], resultDP[i] + nums[i]);
      // Return Max Value
      return resultDP[n + 1];
    };

    // Dynamic Programming Top Down
    const function<int(int)> runTopDownDP = [&](int i) {
      // Base Case
      if (i < 0) return 0;
      // Memorization
      if (resultDP[i + 2] >= 0) return resultDP[i + 2];
      // Store Value & Return
      return resultDP[i + 2] =
                 max(runTopDownDP(i - 1), runTopDownDP(i - 2) + nums[i]);
    };

    // Runtime O(N)
    // Space O(N)
    return runTopDownDP(n - 1);
  }
};
