#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int tribonacci(int n) {
    if (n <= 1) return n;
    if (n == 2) return 1;
    auto DP = new uint32_t[n + 1];
    DP[0] = 0, DP[1] = 1, DP[2] = 1;
    for (uint8_t i = 3; i <= n; ++i) DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
    return DP[n];
  }
};
