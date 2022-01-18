#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    const uint16_t size = flowerbed.size();
    for (uint16_t i = 0; i < size; ++i) {
      if ((flowerbed[i] == 0) && (i == 0 ? true : flowerbed[i - 1] == 0) &&
          (i == size - 1 ? true : flowerbed[i + 1] == 0)) {
        flowerbed[i] = 1;
        --n;
      }
    }
    return n <= 0;
  }
};
