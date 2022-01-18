#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) noexcept {
    const uint16_t n = cost.size();
    auto DP = new uint32_t[n]();
    for (uint16_t i = 2; i < n; ++i)
      DP[i] = min(DP[i - 1] + cost[i - 1], DP[i - 2] + cost[i - 2]);
    return min(DP[n - 1] + cost[n - 1], DP[n - 2] + cost[n - 2]);
  }
};

#if 0  // Also Works, Same Speed
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) noexcept {
    const uint16_t n = cost.size();
    auto DP = new uint32_t[n];
    DP[0] = cost[0];
    DP[1] = cost[1];
    for (uint16_t i = 2; i < n; ++i)
      DP[i] = min(DP[i - 1] + cost[i], DP[i - 2] + cost[i]);
    return min(DP[n - 1], DP[n - 2]);
  }
};
#endif
