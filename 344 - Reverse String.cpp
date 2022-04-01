#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution                                        {
 public:
  static void reverseString(vector<char>& s) noexcept {
    int l = 0, r = s.size() - 1                       ;
    while (l < r)                                     {
      swap(s[l++], s[r--])                            ;
                                                      }
                                                      }
                                                      };
