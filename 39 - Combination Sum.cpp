#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int Target;
  vector<vector<int>> Result;

  void DFS(const vector<int>& candidates, int Sum, vector<int>& Curr,
           int Allowed) {
    // Base Case
    if (Sum == Target) {
      Result.push_back(Curr);
      return;
    }
    if (Sum > Target || Allowed >= candidates.size()) return;
    // Recursion
    const int candidate = candidates[Allowed];
    Curr.push_back(candidate);
    this->DFS(candidates, Sum + candidate, Curr, Allowed);
    Curr.pop_back();
    this->DFS(candidates, Sum, Curr, Allowed + 1);
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    this->Target = target;
    vector<int> __T_PARAM_01;
    this->DFS(candidates, 0, __T_PARAM_01, 0);
    return Result;
  }
};

#if 0  // Works, Slow
class Solution {
  int Target;

  void DFS(const vector<int>& candidates, vector<int>& Curr,
           vector<vector<int>>& Result, int Sum) noexcept {
    const uint8_t size = candidates.size();
    for (uint8_t i = 0; i < size; ++i) {
      const auto& candidate = candidates[i];
      Curr.push_back(candidate);
      Sum += candidate;
      if (Sum == Target)
        Result.push_back(Curr);
      else if (Sum < Target)
        DFS(candidates, Curr, Result, Sum);
      Curr.pop_back();
      Sum -= candidate;
    }
  }

 public:
  vector<vector<int>> combinationSum(const vector<int>& candidates,
                                     int target) noexcept {
    vector<int> Curr;
    vector<vector<int>> Result;
    this->Target = target;
    this->DFS(candidates, Curr, Result, 0);
    set<vector<int>> R;
    for (auto& i : Result) sort(i.begin(), i.end()), R.insert(move(i));
    return {R.begin(), R.end()};
  }
};
#endif
