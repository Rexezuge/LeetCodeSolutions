#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static bool searchMatrix(const vector<vector<int>>& matrix,
                           const int target) noexcept {
    const int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m * n - 1;
    while (l <= r) {
      int midIdx = l + (r - l) / 2, midVal = matrix[midIdx / n][midIdx % n];
      if (midVal == target) return true;
      target < midVal ? r = midIdx - 1 : l = midIdx + 1;
    }

    // Runtime O(M*N)
    // Space O(1)
    return false;
  }
};
