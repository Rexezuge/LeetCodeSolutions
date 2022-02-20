#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  using Interval = vector<int>;

 public:
  static int removeCoveredIntervals(vector<Interval>& intervals) noexcept {
    sort(intervals.begin(), intervals.end());

    int num_intervals = 1;
    int begin = intervals[0][0], end = intervals[0][1];

    for (int i = 1, n = intervals.size(); i < n; ++i) {
      if (intervals[i][0] > begin && intervals[i][1] > end) ++num_intervals;
      if (intervals[i][1] > end) begin = intervals[i][0], end = intervals[i][1];
    }

    return num_intervals;
  }
};
