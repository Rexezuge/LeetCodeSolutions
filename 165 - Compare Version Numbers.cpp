#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int compareVersion(string_view version1, string_view version2) {
    for (int iX = 0, iY = 0, n1 = version1.size(), n2 = version2.size(), num1,
             num2;
         iX < n1 || iY < n2; ++iX, ++iY) {
      num1 = 0, num2 = 0;
      while (iX < n1 && version1[iX] != '.')
        num1 = num1 * 10 + (version1[iX] - '0'), ++iX;
      while (iY < n2 && version2[iY] != '.')
        num2 = num2 * 10 + (version2[iY] - '0'), ++iY;
      if (num1 != num2) return num1 < num2 ? -1 : 1;
    }
    return 0;
  }
};
