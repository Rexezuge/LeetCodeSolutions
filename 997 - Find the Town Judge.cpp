#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findJudge(int n, const vector<vector<int>>& trust) {
    int16_t* DegreeMap = new int16_t[n]();
    for (const auto& i : trust) ++DegreeMap[i[0] - 1], --DegreeMap[i[1] - 1];
    for (int i = 0, __T_TARGET = 1 - n; i < n; ++i)
      if (DegreeMap[i] == __T_TARGET) return i + 1;
    return -1;
  }
};

#if 0  // Works, But Slow
class Solution {
  using NodeID = int;

 public:
  int findJudge(int n, const vector<vector<int>>& trust) {
    if (n == 1) return n;
    // Construct In-Degree Map
    unordered_map<NodeID, vector<NodeID>> Trusts(n);
    unordered_map<NodeID, vector<NodeID>> TrustBy(n);
    for (const auto& i : trust) {
      Trusts[i[0] - 1].push_back(i[1] - 1);
      TrustBy[i[1] - 1].push_back(i[0] - 1);
    }
    for (auto iTR = TrustBy.begin(); iTR != TrustBy.end(); ++iTR)
      if (iTR->second.size() == n - 1 && Trusts[iTR->first].size() == 0)
        return iTR->first + 1;
    return -1;
  }
};
#endif
