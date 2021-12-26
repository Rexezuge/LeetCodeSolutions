#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string& R = strs[0];
    for (size_t i = 1; i < strs.size() && !R.empty(); ++i) {
      if (R.size() > strs[i].size()) {
        strs[i] = strs[i].substr(0, R.size());
      }
      while (R != strs[i].substr(0, R.size()) && !R.empty()) {
        R.pop_back();
      }
    }
    return R;
  }
};
