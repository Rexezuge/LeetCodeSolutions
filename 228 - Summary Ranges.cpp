#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<string> summaryRanges(const vector<int>& nums) noexcept {
    // Edge Case
    if (nums.size() == 0) return {};
    if (nums.size() == 1) return {to_string(nums[0])};

    // Variable Initialization
    const int n = nums.size();
    int lastVal = nums[0];
    vector<string> retVec;

    // Perform the Algorithm
    for (int i = 0; i < n; ++i) {
      if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
        if (nums[i] == lastVal)
          retVec.push_back(to_string(nums[i]));
        else
          retVec.push_back(to_string(lastVal) + "->" + to_string(nums[i]));
        if (i != n - 1) lastVal = nums[i + 1];
      }
    }

    // Runtime O(N)
    // Space O(N)
    return retVec;
  }
};
