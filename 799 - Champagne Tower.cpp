#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static double champagneTower(int poured, int query_row,
                               int query_glass) noexcept {
    // Variable Initialization
    vector<vector<double>> valTower(102, vector<double>(102));

    // Base Case
    valTower[0][0] = static_cast<double>(poured);

    // Perform Algorithm
    for (int iX = 0; iX < query_row; ++iX) {
      for (int iY = 0; iY <= iX; ++iY) {
        double extraFlow = (valTower[iX][iY] - 1.0) / 2.0;
        if (extraFlow > 0.0)
          valTower[iX + 1][iY] += extraFlow,
              valTower[iX + 1][iY + 1] += extraFlow;
      }
    }

    // Runtime O(N*N)
    // Space O(N*N)
    return min(1.0, valTower[query_row][query_glass]);
  }
};
