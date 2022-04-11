#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<vector<int>> shiftGrid(const vector<vector<int>>& grid,
                                       int k) noexcept {
    // Variable Initialization
    vector<vector<int>> retVal = grid;

    // Helper Function Initialization
    function<void(void)> shiftOnce = [&](void) {
      vector<int> backCol(retVal.size());
      for (int i = 0; i < retVal.size(); ++i) backCol[i] = retVal[i].back();
      for (int iX = retVal.size() - 1; iX >= 0; --iX)
        for (int iY = retVal[0].size() - 1; iY > 0; --iY)
          retVal[iX][iY] = retVal[iX][iY - 1];
      for (int i = 1; i < retVal.size(); ++i) retVal[i][0] = backCol[i - 1];
      retVal[0][0] = backCol.back();
    };

    // Construct New Shifted Grid
    for (int i = 0; i < k; ++i) shiftOnce();

    // Runtime O(M*N)
    // Space O(M*N)
    return retVal;
  }
};
