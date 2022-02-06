#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int removeDuplicates(vector<int>& Nums, int i = 0) noexcept {
    for (const auto& Val : Nums)
      if (i < 2 || Val > Nums[i - 2]) Nums[i++] = Val;
    return i;
  }
};
