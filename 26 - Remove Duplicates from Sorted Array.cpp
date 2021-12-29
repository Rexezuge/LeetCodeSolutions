#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
      return {0};
    }
    int iTR_UNIQUE = 0, iTR_DUPLICATE = 0;
    while (++iTR_DUPLICATE < nums.size()) {
      if (nums[iTR_UNIQUE] != nums[iTR_DUPLICATE]) {
        nums[++iTR_UNIQUE] = nums[iTR_DUPLICATE];
      }
    }
    return {iTR_UNIQUE + 1};
  }
};
