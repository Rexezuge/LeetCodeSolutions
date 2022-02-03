#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int fourSumCount(const vector<int>& nums1, const vector<int>& nums2,
                          const vector<int>& nums3,
                          const vector<int>& nums4) noexcept {
    const uint8_t n = nums1.size();

    unordered_map<int, int> HashMap;

    for (const auto iX : nums1)
      for (const auto iY : nums2) ++HashMap[iX + iY];

    uint Result = 0;

    for (const auto iX : nums3)
      for (const auto iY : nums4) Result += HashMap[-1 * (iX + iY)];

    return Result;
  }
};
