#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int Current = 0;
    int Total = 0;
    int Diff = 0;
    int Start = 0;

    for (int i = 0; i < gas.size(); i++) {
      Diff = gas[i] - cost[i];
      Total += Diff;
      Current += Diff;
      if (Current < 0) {
        Current = 0;
        Start = i + 1;
      }
    }

    if (Total >= 0) {
      return Start;
    }
    return -1;
  }
};

#if 0  // Should be Correct, But is Wrong
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) noexcept {
    if (accumulate(gas.begin(), gas.end(), 0) <
        accumulate(cost.begin(), cost.end(), 0))
      return -1;
    int Index = 0, Sum = 0;
    uint16_t n = gas.size();
    for (uint16_t i = 0; i < n; ++i) {
      Sum += gas[i] - cost[i];
      if (Sum < 0) Sum = 0, Index = i + 1;
    }
    return Index;
  }
};
#endif
