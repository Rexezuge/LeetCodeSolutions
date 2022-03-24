#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static bool isValidSudoku(const vector<vector<char>>& board) noexcept {
    // Check Each Sub-Sudoku
    for (int iX = 0; iX < 9; iX += 3) {
      for (int iY = 0; iY < 9; iY += 3) {
        unique_ptr<uint8_t[]> numAppeared(new uint8_t[9]());
        for (int R = iX; R < iX + 3; ++R)
          for (int C = iY; C < iY + 3; ++C)
            if (board[R][C] != '.' && ++numAppeared[board[R][C] - '1'] > 1)
              return false;
      }
    }

    // Check Each Column
    for (int R = 0; R < 9; ++R) {
      unique_ptr<uint8_t[]> numAppeared(new uint8_t[9]());
      for (int C = 0; C < 9; ++C)
        if (board[R][C] != '.' && ++numAppeared[board[R][C] - '1'] > 1)
          return false;
    }

    // Check Each Row
    for (int C = 0; C < 9; ++C) {
      unique_ptr<uint8_t[]> numAppeared(new uint8_t[9]());
      for (int R = 0; R < 9; ++R)
        if (board[R][C] != '.' && ++numAppeared[board[R][C] - '1'] > 1)
          return false;
    }

    return true;
  }
};
