#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> Result;
    for (size_t i = 0, size = nums.size(); i < size; ++i) {
      const size_t Index = abs(nums[i]) - 1;
      if (nums[Index] > 0) nums[Index] = -1 * nums[Index];
    }
    for (size_t i = 0, size = nums.size(); i < size; ++i)
      if (nums[i] > 0) Result.push_back(i + 1);
    return Result;
  }
};

#if 0  // Works, But Slow
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> Result;
    vector<int> Appeared(nums.size(), 0);
    for (const auto& i : nums) ++Appeared[i - 1];
    for (size_t i = 0; i < Appeared.size(); ++i)
      if (Appeared[i] == 0) Result.push_back(i + 1);
    return Result;
  }
};
#endif
