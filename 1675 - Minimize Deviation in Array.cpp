#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int minimumDeviation(const vector<int>& nums) noexcept {
    priority_queue<int> PQ;

    int Min_Value = INT_MAX, Diff_Val = INT_MAX;

    // Make All Odd Numbers Even
    for (int i : nums) {
      i = (i % 2 == 1) ? (i << 1) : (i);
      PQ.push(i);
      Min_Value = min(Min_Value, i);
    }

    // Keep Decreasing the Max Even Number
    while (PQ.top() % 2 == 0) {
      const int Val = PQ.top();
      Diff_Val = min(Diff_Val, Val - Min_Value);
      Min_Value = min(Min_Value, Val >> 1);
      PQ.pop();
      PQ.push(Val >> 1);
    }

    return min(Diff_Val, PQ.top() - Min_Value);
  }
};
