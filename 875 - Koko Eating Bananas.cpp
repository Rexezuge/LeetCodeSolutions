#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) noexcept {
    int32_t Left = 1, Right = *max_element(piles.begin(), piles.end());
    while (Left < Right) {
      const uint32_t Mid = Left + (Right - Left) / 2;
      uint32_t Hours = 0;
      for (const auto& Pile : piles) Hours += Pile / Mid + (Pile % Mid != 0);
      if (Hours <= h)
        Right = Mid;
      else
        Left = Mid + 1;
    }
    return Right;
  }
};
