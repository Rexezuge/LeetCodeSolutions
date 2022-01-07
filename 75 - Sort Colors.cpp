#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    // Initilization
    int End = 0;
    // Swap Red
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == 0) swap(nums[End], nums[i]), ++End;
    // Swap White
    for (int i = End; i < nums.size(); ++i)
      if (nums[i] == 1) swap(nums[End], nums[i]), ++End;
  }
};
