#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static bool isPalindrome(string_view s) noexcept {
    int l = 0, r = s.size() - 1;

    // Perform Two Pointers
    while (l < r) {
      // Skip Non-Alpha Characters
      while (l < r && isalnum(s[l]) == 0) ++l;
      while (l < r && isalnum(s[r]) == 0) --r;
      if (tolower(s[l]) != tolower(s[r])) return false;
      ++l, --r;
    }

    // Runtime O(N)
    // Space O(1)
    return true;
  }
};
