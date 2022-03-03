#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int numberOfArithmeticSlices(const vector<int>& nums) noexcept {
    // Edge Case
    if (nums.size() < 3) return 0;

    // Variable Initialization
    int retCounter = 0, currCounter = 0, prevDiff = nums[0] - nums[1];

    // Perform the Algorithm
    for (int i = 1, __i_LOOP_END = nums.size() - 1; i < __i_LOOP_END; ++i) {
      int currDiff = nums[i] - nums[i + 1];
      if (currDiff == prevDiff)
        ++currCounter;
      else
        prevDiff = currDiff, currCounter = 0;
      retCounter += currCounter;
    }

    // Runtime O(N)
    // Space O(1)
    return retCounter;
  }
};

#if 0
class Solution {
 public:
  static int numberOfArithmeticSlices(const vector<int>& nums) noexcept {
    // Edge Case
    if (nums.size() < 3) return 0;

    // Variable Initialization
    int retCounter = 0;

    // Perform the Algorithm
    for (int iX = 0, __iX_LOOP_END = nums.size() - 2; iX < __iX_LOOP_END;
         ++iX) {
      int currDiff = nums[iX] - nums[iX + 1];
      for (int iY = iX + 1, __iY_LOOP_END = nums.size() - 1; iY < __iY_LOOP_END;
           ++iY)
        if (nums[iY] - nums[iY + 1] == currDiff)
          ++retCounter;
        else
          break;
    }

    // Runtime O(N*N)
    // Space O(1)
    return retCounter;
  }
};
#endif
