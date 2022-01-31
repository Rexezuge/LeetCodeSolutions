#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximumWealth(const vector<vector<int>>& accounts,
                    int m = INT_MIN) noexcept {
    for (const auto& Vec : accounts)
      m = max(accumulate(Vec.begin(), Vec.end(), 0), m);
    return m;
  }
};

#if 0  // Same Approach
class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int MaxWealth = 0;
    const int size_iX = accounts.size();
    const int size_iY = accounts[0].size();
    for (int iX = 0; iX < size_iX; ++iX) {
      int CurrentWealth = 0;
      for (int iY = 0; iY < size_iY; ++iY) CurrentWealth += accounts[iX][iY];
      MaxWealth = max(MaxWealth, CurrentWealth);
    }
    return MaxWealth;
  }
};
#endif
