#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& Prices) const noexcept {
    const int n = Prices.size();

    int MaxValue = 0;
    int MinValue = INT_MAX;

    for (int i = 0; i < n; ++i) {
      MinValue = min(MinValue, Prices[i]);
      MaxValue = max(MaxValue, Prices[i] - MinValue);
    }

    return MaxValue;
  }
};

#if 0  // Works, Dynamic Programming
class Solution {
 public:
  int maxProfit(const vector<int>& Prices) const noexcept {
    const int n = Prices.size();

    auto MinArray = Prices;
    for (int i = 1; i < n; ++i) MinArray[i] = min(MinArray[i], MinArray[i - 1]);

    int MaxValue = 0;
    for (int i = 0; i < n; ++i)
      MaxValue = max(MaxValue, Prices[i] - MinArray[i]);

    return MaxValue;
  }
};
#endif
