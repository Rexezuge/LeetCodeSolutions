#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<vector<int>> permute(const vector<int>& nums) noexcept {
    // Variable Initialization
    unordered_set<int> usedIndex;
    vector<int> currPath;
    vector<vector<int>> retVal;

    // Recursion Function
    const function<void(int, int)> runRecursion = [&](int pathCount,
                                                      const int endingIndex) {
      // Base Case
      if (pathCount >= endingIndex) retVal.push_back(currPath);
      // Recursion
      for (int i = 0; i < endingIndex; ++i) {
        if (usedIndex.count(i) > 0) continue;
        currPath.push_back(nums[i]);
        usedIndex.insert(i);
        runRecursion(pathCount + 1, endingIndex);
        currPath.pop_back();
        usedIndex.erase(i);
      }
    };

    // Run Recursion Function
    runRecursion(0, nums.size());

    // Runtime O(N*N)
    // Space O(N*N)
    return retVal;
  }
};
