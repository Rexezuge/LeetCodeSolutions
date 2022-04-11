#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<vector<string>> groupAnagrams(
      const vector<string>& strs) noexcept {
    // Variable Initialization
    unordered_map<string, vector<string>> uMap;
    vector<vector<string>> retVal;

    // Construct the Map
    for (const string& s : strs) {
      string r = s;
      sort(r.begin(), r.end());
      uMap[r].push_back(s);
    }

    // Construct Return Vector
    for (const auto& [k, v] : uMap) retVal.push_back(v);

    // Runtime O(N*NlogN)
    // Space O(N)
    return retVal;
  }
};
