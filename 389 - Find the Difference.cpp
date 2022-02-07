#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static char findTheDifference(string_view s, string_view t) noexcept {
    auto Map = new int8_t[26]();

    for (const char c : s) ++Map[c - 'a'];

    for (const char c : t)
      if ((--Map[c - 'a']) < 0) return c;

    return {};
  }
};
