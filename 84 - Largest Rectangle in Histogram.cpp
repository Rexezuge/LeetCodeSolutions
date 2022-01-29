#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(const vector<int>& heights) const noexcept {
    const int n = heights.size();
    stack<pair<int, int>> Histogram;
    int MaxValue = 0;

    for (int i = 0; i < n; ++i) {
      int PrevIndex = i;
    __L_CHECK_STACK:;
      if (!Histogram.empty()) {
        const auto& [Index, Value] = Histogram.top();
        if (Value > heights[i]) {
          PrevIndex = Index;
          MaxValue = max(MaxValue, Value * (i - Index));
          Histogram.pop();
          goto __L_CHECK_STACK;
        }
      }
      Histogram.push({PrevIndex, heights[i]});
    }

    while (!Histogram.empty()) {
      const auto& [Index, Value] = Histogram.top();
      MaxValue = max(MaxValue, Value * (n - Index));
      Histogram.pop();
    }

    return MaxValue;
  }
};
