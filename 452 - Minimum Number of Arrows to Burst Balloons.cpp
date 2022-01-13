#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) noexcept {
    // Sort X.end in ascending order
    sort(points.begin(), points.end(),
         [&](const auto& A, const auto& B) { return A[1] < B[1]; });
    // Find number of arrows needed
    int Right = points[0][1];
    int Arrow = 1;
    for (const auto& i : points)
      if (i[0] > Right) ++Arrow, Right = i[1];
    return Arrow;
  }
};
