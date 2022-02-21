#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int majorityElement(vector<int>& nums) noexcept {
    // Boyer-Moore Voting Algorithm
    int Val = nums[0], Count = 0;
    for (int i = 1, n = nums.size(); i < n; ++i) {
      Val == nums[i] ? ++Count : --Count;
      if (Count < 0) Val = nums[i], Count = 0;
    }
    return Val;
  }
};
