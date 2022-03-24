#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<vector<int>> combinationSum2(vector<int>& candidates,
                                             const int target) noexcept {
    // Sort Input Since We Need Unique Solutions
    sort(candidates.begin(), candidates.end());

    // Variable Initialization
    vector<int> currPath;
    vector<vector<int>> retVal;

    // Perform the Algorithm
    function<void(int, int)> recurFunc = [&](int numIdx, int currSum) {
      if (currSum == target) {
        retVal.push_back(currPath);
        return;
      }
      for (int i = numIdx, __END = candidates.size(); i < __END; ++i) {
        if (i > numIdx && candidates[i] == candidates[i - 1]) continue;
        currPath.push_back(candidates[i]), currSum += candidates[i];
        if (currSum <= target) recurFunc(i + 1, currSum);
        currPath.pop_back(), currSum -= candidates[i];
      }
    };
    recurFunc(0, 0);

    // Runtime (N*N)
    // Space (N)
    return retVal;
  }
};
