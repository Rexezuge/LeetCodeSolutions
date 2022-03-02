#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static bool isSubsequence(string_view s, string_view t, int iX = 0) noexcept {
    for (int iY = 0, NX = s.size(), NY = t.size(); iX < NX && iY < NY; ++iY)
      if (s[iX] == t[iY]) ++iX;

    // Runtime O(N)
    // Space O(1)
    return iX == s.size();
  }
};
