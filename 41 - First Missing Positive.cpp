#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    // Initialization
    const size_t size = nums.size();
    for (auto& i : nums)
      if (i < 0) i = 0;
    // Map Hash Map
    for (size_t i = 0; i < size; ++i) {
      const int Index = abs(nums[i]) - 1;
      if (Index >= 0 && Index < size)
        if (nums[Index] > 0)
          nums[Index] = (-1) * nums[Index];
        else if (nums[Index] == 0)
          nums[Index] = INT32_MIN;
    }
    // Yay!
    int Missing = 1;
    for (size_t i = 0; i < size; ++i)
      if (nums[Missing - 1] < 0)
        ++Missing;
      else
        return Missing;
    return Missing;
  }
};
