#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int search(const vector<int>& nums, int target) noexcept {
    // Binary Search
    int leftIdx = 0, rightIdx = nums.size() - 1;
    while (leftIdx <= rightIdx) {
      int midIdx = leftIdx + (rightIdx - leftIdx) / 2;
      int midVal = nums[midIdx];
      if (midVal == target)
        return midIdx;
      else if (midVal < target)
        leftIdx = midIdx + 1;
      else
        rightIdx = midIdx - 1;
    }

    // Runtime O(logN)
    // Space O(1)
    return -1;
  }
};
