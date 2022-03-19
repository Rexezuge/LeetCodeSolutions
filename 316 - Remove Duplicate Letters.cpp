#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static string removeDuplicateLetters(string_view s) noexcept {
    // Variable Initialization
    unique_ptr<int[]> numAppeared(new int[26]());
    unique_ptr<bool[]> withinResult(new bool[26]());
    string retVal;

    // Count Appeared Letter
    for (char c : s) ++numAppeared[c - 'a'];

    // Construct Return String
    for (char c : s) {
      --numAppeared[c - 'a'];
      if (withinResult[c - 'a'] == false) {
        while (retVal.size() > 0 && retVal.back() > c &&
               numAppeared[retVal.back() - 'a'] > 0) {
          withinResult[retVal.back() - 'a'] = false;
          retVal.pop_back();
        }
        retVal.push_back(c);
        withinResult[c - 'a'] = true;
      }
    }

    // Runtime O(N)
    // Space O(N)
    return retVal;
  }
};
