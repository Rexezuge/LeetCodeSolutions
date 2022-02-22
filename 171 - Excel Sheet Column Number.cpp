#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int titleToNumber(string_view columnTitle, int retVal = 0) noexcept {
    for (int i = 0, n = columnTitle.size(); i < n; ++i)
      retVal += (columnTitle[i] - 'A' + 1) * pow(26, n - i - 1);

    return retVal;
  }
};
