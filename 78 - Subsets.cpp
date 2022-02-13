#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<vector<int>> subsets(const vector<int>& nums) noexcept {
    vector<vector<int>> Result;
    Result.push_back({});

    vector<int> CurrPath;
    function<void(int)> DFS = [&](int Index) {
      CurrPath.push_back(nums[Index]);
      Result.push_back(CurrPath);

      for (int i = Index + 1; i < nums.size(); ++i) DFS(i);

      CurrPath.pop_back();
    };

    for (int i = 0; i < nums.size(); ++i) DFS(i);

    return Result;
  }
};
