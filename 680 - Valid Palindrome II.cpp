#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static bool validPalindrome(string_view s, int l = 0, int r = -1,
                              int canDelete = true) noexcept {
    // Function Default Parameters
    if (r < 0) r = s.size() - 1;

    // Perform Two Pointers
    while (l < r) {
      // Two End Matches
      if (s[l] == s[r]) {
        ++l, --r;
        continue;
      }
      // Two End Does NOT Match
      if (canDelete == false) return false;
      return validPalindrome(s, l, r - 1, false) ||
             validPalindrome(s, l + 1, r, false);
    }

    // Runtime O(N)
    // Space O(1)
    return true;
  }
};
