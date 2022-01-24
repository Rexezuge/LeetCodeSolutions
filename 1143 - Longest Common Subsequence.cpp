#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(const string& text1,
                               const string& text2) noexcept {
    auto DP = new int16_t*[text1.size() + 1];
    for (int16_t i = 0; i < text1.size() + 1; ++i)
      DP[i] = new int16_t[text2.size() + 1]();
    for (int16_t i = text1.size() - 1; i >= 0; --i)
      for (int16_t j = text2.size() - 1; j >= 0; --j)
        if (text1[i] == text2[j])
          DP[i][j] = 1 + DP[i + 1][j + 1];
        else
          DP[i][j] = max(DP[i][j + 1], DP[i + 1][j]);
    return DP[0][0];
  }
};
