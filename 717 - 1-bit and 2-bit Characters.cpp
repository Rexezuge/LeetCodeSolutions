#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) noexcept {
    const uint16_t size = bits.size();
    for (uint16_t i = 0; i < size; ++i)
      if (bits[i] == 0) {
        if (i + 1 == size) return true;
      } else
        ++i;
    return false;
  }
};
