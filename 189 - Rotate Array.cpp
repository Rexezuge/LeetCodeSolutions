#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) noexcept {
    int n = nums.size();

    k = k % n;

    reverse(nums.begin(), nums.end());

    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

#if 0  // Works, Using Extra Space
class Solution {
 public:
  void rotate(vector<int>& nums, int k) noexcept {
    int n = nums.size();

    k = k % n;

    vector<int> Rotate;
    Rotate.reserve(n);

    for (int i = n - k; i < n; ++i) Rotate.push_back(move(nums[i]));
    for (int i = 0; i < n - k; ++i) Rotate.push_back(move(nums[i]));

    nums = move(Rotate);
  }
};
#endif
