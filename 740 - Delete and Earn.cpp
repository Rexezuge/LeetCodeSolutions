#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) noexcept {
    // Initialization
    map<uint16_t, uint16_t> M;
    for (const auto& i : nums) ++M[i];
    // Dynamic Programming
    uint32_t DP_1 = 0, DP_2 = 0;
    for (auto i = M.begin(); i != M.end(); ++i) {
      uint32_t Current = i->first * i->second;
      auto Prev = i;
      if (Prev != M.begin()) --Prev;
      if (Prev->first + 1 == i->first)
        Current = max(Current + DP_1, DP_2);
      else
        Current += DP_2;
      swap(DP_1, DP_2);
      DP_2 = Current;
    }
    // Yay!
    return DP_2;
  }
};
