#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int maxSubArray(const vector<int>& nums) noexcept;
};

int Solution::maxSubArray(const vector<int>& nums) noexcept {
  // Max Sub Array Result
  int maxValue = nums[0];

  // Current Sub Array
  int currValue = nums[0], currIndex = 0;

  // Sliding Window
  int n = nums.size();
  while (++currIndex < n) {
    if (currValue < 0 && currValue < nums[currIndex]) currValue = 0;
    currValue += nums[currIndex];
    maxValue = max(maxValue, currValue);
  }

  return maxValue;
}
