#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int subarraySum(vector<int>& nums, int k) noexcept {
    unordered_map<int, int> Appeared;

    Appeared.insert({0, 1});

    int Sum = 0;
    int Count = 0;

    for (const int i : nums) {
      Sum += i;
      if (Appeared.count(Sum - k) > 0) Count += Appeared[Sum - k];
      Appeared[Sum]++;
    }

    return Count;
  }
};
