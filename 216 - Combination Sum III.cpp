#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<vector<int>> combinationSum3(const int k,
                                             const int n) noexcept {
    // Variable Initialization
    vector<int> currPath;
    vector<vector<int>> retVal;

    // Perform the Algorithm
    function<void(int, int)> recurFunc = [&](int numIdx, int currSum) {
      if (currSum == n && currPath.size() == k) {
        retVal.push_back(currPath);
        return;
      }
      for (int i = numIdx; i <= 9; ++i) {
        currPath.push_back(i);
        if (currPath.size() <= n) recurFunc(i + 1, currSum + i);
        currPath.pop_back();
      }
    };
    recurFunc(1, 0);

    // Runtime O(N*N)
    // Space O(N)
    return retVal;
  }
};
