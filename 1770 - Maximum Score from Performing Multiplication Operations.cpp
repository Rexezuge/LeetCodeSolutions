#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    const uint32_t n = nums.size();
    const uint32_t m = multipliers.size();
    int32_t* DP[m + 1];
    for (uint32_t i = 0; i < m + 1; ++i) DP[i] = new int32_t[m + 1]();
    for (int32_t i = m - 1; i >= 0; --i) {
      for (int32_t Left = i; Left >= 0; --Left) {
        const auto Mult = multipliers[i];
        const int32_t Right = n - 1 - (i - Left);
        DP[i][Left] = max(Mult * nums[Left] + DP[i + 1][Left + 1],
                          Mult * nums[Right] + DP[i + 1][Left]);
      }
    }
    return DP[0][0];
  }
};
