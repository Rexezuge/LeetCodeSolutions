#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static void nextPermutation(vector<int>& nums) noexcept {
    next_permutation(nums.begin(), nums.end());
  }
};
