#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  enum { NOW_DEAD = 0, NOW_LIVE = 1, NEXT_DEAD = -1, NEXT_LIVE = 2 };

 public:
  static void gameOfLife(vector<vector<int>>& board) noexcept;
};

void Solution::gameOfLife(vector<vector<int>>& board) noexcept {
  // Static Initialization
  static const int X_Directions[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
  static const int Y_Directions[8] = {0, 1, 1, 1, 0, -1, -1, -1};

  // Variable Initialization
  const size_t m = board.size(), n = board[0].size();

  // Helper Function Implementation
  const function<bool(int, int)> insideBoundary = [&](int x, int y) {
    return (x >= 0 && x < m) && (y >= 0 && y < n);
  };
  const function<int(int, int)> getLiveNeighbors = [&](int x_old, int y_old) {
    int retVal = 0;
    for (int i = 0; i < 8; ++i) {
      int x = x_old + X_Directions[i], y = y_old + Y_Directions[i];
      if (insideBoundary(x, y) &&
          (board[x][y] == NOW_LIVE || board[x][y] == NEXT_DEAD))
        ++retVal;
    }
    return retVal;
  };

  // First Iteration, Marking Changes
  for (size_t r = 0; r < m; ++r) {
    for (size_t c = 0; c < n; ++c) {
      int liveNeighbors = getLiveNeighbors(r, c);
      if (board[r][c] == NOW_DEAD && liveNeighbors == 3)
        board[r][c] = NEXT_LIVE;
      else if (board[r][c] == NOW_LIVE &&
               (liveNeighbors < 2 || liveNeighbors > 3))
        board[r][c] = NEXT_DEAD;
    }
  }

  // Second Iteration, Applying Changes
  for (size_t r = 0; r < m; ++r) {
    for (size_t c = 0; c < n; ++c) {
      switch (board[r][c]) {
        case NEXT_LIVE:
          board[r][c] = NOW_LIVE;
          break;
        case NEXT_DEAD:
          board[r][c] = NOW_DEAD;
          break;
      };
    }
  }

  // Runtime O(M*N)
  // Space O(1)
  return;
}
