#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int singleNumber(vector<int>& nums) noexcept {
    // 4^1^2^2^1 --> 4^(1^1) ^ (2^2) --> 4 ^ (0) ^(0) --> 4
    int Val = nums[0], n = nums.size();
    for (int i = 1; i < n; i++) Val ^= nums[i];
    return Val;
  }
};
