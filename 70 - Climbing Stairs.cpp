#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_map<int, int> M;
  int DP(int n) {
    if (n <= 2) return n;
    if (M[n - 1] == 0) M[n - 1] = DP(n - 1);
    if (M[n - 2] == 0) M[n - 2] = DP(n - 2);
    return M[n - 1] + M[n - 2];
  }

 public:
  int climbStairs(int n) { return DP(n); }
};
