#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int searchInsert(vector<int>& nums, int target) noexcept {
    int n = nums.size(), lower = 0, upper = n - 1, pos = -1;
    if (target < nums[0]) return 0;
    while (lower <= upper) {
      int mid = lower + (upper - lower) / 2;
      if (nums[mid] < target)
        lower = mid + 1;
      else if (nums[mid] > target)
        upper = mid - 1, pos = mid;
      else if (nums[mid] == target)
        return mid;
    }
    return pos < 0 ? n : pos;
  }
};
