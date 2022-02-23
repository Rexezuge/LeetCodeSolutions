#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<int> searchRange(const vector<int>& nums, int target) noexcept {
    auto left = lower_bound(nums.begin(), nums.end(), target);
    if (left == nums.end() || *left != target) return {-1, -1};
    auto right = upper_bound(nums.begin(), nums.end(), target);
    if (right == nums.end())
      return {int(left - nums.begin()), int(nums.size() - 1)};
    return {int(left - nums.begin()), int(right - nums.begin() - 1)};
  }
};

#if 0  // Works, Binary Search
class Solution {
 public:
  static vector<int> searchRange(const vector<int>& nums, int target) noexcept {
    int n = nums.size(), left = 0, right = n - 1;
    int retX = -1, retY = -1;

    while (left <= right && retX < 0) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target)
        left = mid + 1;
      else if (nums[mid] > target)
        right = mid - 1;
      else if (mid > 0 ? nums[mid - 1] < target : true)
        retX = mid;
      else
        --left;
    }

    if (retX < 0) goto L_EXIT;

    left = 0, right = n - 1;
    while (left <= right && retY < 0) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target)
        left = mid + 1;
      else if (nums[mid] > target)
        right = mid - 1;
      else if (mid < n - 1 ? nums[mid + 1] > target : true)
        retY = mid;
      else
        ++right;
    }

  L_EXIT:
    return {retX, retY};
  }
};
#endif
