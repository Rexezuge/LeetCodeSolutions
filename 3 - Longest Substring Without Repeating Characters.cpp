#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(const string& s) const {
    if (s.empty()) {
      return 0;
    }
    uint16_t MAX_SUBSTR = 1;
    auto HEAD = s.begin();
    auto TAIL = s.begin();
    unordered_set<char> DUP;
    while (TAIL != s.end()) {
      // Sliding Window
      while (DUP.insert(*TAIL).second == false) {
        DUP.erase(*HEAD);
        ++HEAD;
      }
      if (DUP.size() > MAX_SUBSTR) {
        MAX_SUBSTR = DUP.size();
      }
      ++TAIL;
    }
    return MAX_SUBSTR;
  }
};
