#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int16_t ROWS, COLS;
  mutable unordered_map<int16_t, unordered_map<int16_t, int16_t>> DP;

  int16_t DFS(const vector<vector<char>>& matrix, int16_t r,
              int16_t c) const noexcept {
    if (r >= ROWS || c >= COLS) return 0;
    if (DP.count(r) < 1 || DP[r].count(c) < 1) {
      auto Down = DFS(matrix, r + 1, c);
      auto Right = DFS(matrix, r, c + 1);
      auto Diag = DFS(matrix, r + 1, c + 1);
      if (matrix[r][c] == '1') DP[r][c] = 1 + min(Down, min(Right, Diag));
    }
    return DP[r][c];
  }

 public:
  int maximalSquare(const vector<vector<char>>& matrix) noexcept {
    ROWS = matrix.size();
    COLS = matrix[0].size();
    DFS(matrix, 0, 0);
    int16_t Max = 0;
    for (const auto& [K, R] : DP)
      for (const auto& [K, V] : R) Max = max(Max, V);
    return Max * Max;
  }
};
