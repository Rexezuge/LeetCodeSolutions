#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool mSudokuSolved;

  static bool isValidSudoku(const vector<vector<char>>& board) noexcept;
  static bool isBoardComplete(const vector<vector<char>>& board) noexcept;
  static void canFill(vector<char>* valCanFill,
                      const vector<vector<char>>& board, const int currR,
                      const int currC) noexcept;
  void solveBoard(vector<vector<char>>& board, int currSteps) noexcept;

 public:
  Solution() : mSudokuSolved(false) {}
  void solveSudoku(vector<vector<char>>& board) noexcept;
};

bool Solution::isValidSudoku(const vector<vector<char>>& board) noexcept {
  uint8_t numAppeared[9];

  // Check Each Sub-Sudoku
  for (int iX = 0; iX < 9; iX += 3) {
    for (int iY = 0; iY < 9; iY += 3) {
      memset(numAppeared, 0, sizeof numAppeared);
      for (int R = iX; R < iX + 3; ++R)
        for (int C = iY; C < iY + 3; ++C)
          if (board[R][C] != '.' && ++numAppeared[board[R][C] - '1'] > 1)
            return false;
    }
  }

  // Check Each Column
  for (int R = 0; R < 9; ++R) {
    memset(numAppeared, 0, sizeof numAppeared);
    for (int C = 0; C < 9; ++C)
      if (board[R][C] != '.' && ++numAppeared[board[R][C] - '1'] > 1)
        return false;
  }

  // Check Each Row
  for (int C = 0; C < 9; ++C) {
    memset(numAppeared, 0, sizeof numAppeared);
    for (int R = 0; R < 9; ++R)
      if (board[R][C] != '.' && ++numAppeared[board[R][C] - '1'] > 1)
        return false;
  }

  return true;
}

bool Solution::isBoardComplete(const vector<vector<char>>& board) noexcept {
  for (int R = 0; R < 9; ++R)
    for (int C = 0; C < 9; ++C)
      if (board[R][C] == '.') return false;
  return true;
}

void Solution::canFill(vector<char>* valCanFill,
                       const vector<vector<char>>& board, const int currR,
                       const int currC) noexcept {
  // Clear the Result Vector
  valCanFill->clear();

  // Check Weather a Digit Can Be Placed
  for (char i = '1'; i <= '9'; ++i) {
    bool canPlace = true;

    // Check Row
    for (int R = 0; R < 9; ++R)
      if (board[R][currC] == i) canPlace = false;
    if (canPlace == false) continue;

    // Check Column
    for (int C = 0; C < 9; ++C)
      if (board[currR][C] == i) canPlace = false;
    if (canPlace == false) continue;

    // Check Sub-Sudoku
    for (int RowLevel = currR / 3 * 3, ColLevel = currC / 3 * 3, R = RowLevel;
         R < RowLevel + 3; ++R)
      for (int C = ColLevel; C < ColLevel + 3; ++C) {
        if (board[R][C] == i) canPlace = false;
      }
    if (canPlace == false) continue;
    // Valid Digit
    valCanFill->push_back(i);
  }
}

void Solution::solveBoard(vector<vector<char>>& board, int currSteps) noexcept {
  // Sudoku Already Solved
  if (mSudokuSolved == true) return;

  // Sudoku Successfully Solved
  if (currSteps == 81) {
    mSudokuSolved = true;
    return;
  }

  // Variable Initialization
  int nextR = -1, nextC = -1;
  vector<char> nextDigit;

  // Find the Next Empty Position
  for (int R = 0; R < 9; ++R) {
    for (int C = 0; C < 9; ++C) {
      if (board[R][C] == '.') {
        nextR = R;
        nextC = C;
        break;
      }
    }
    if (nextR >= 0) break;
  }

  // Get All Possible Next Digit
  canFill(&nextDigit, board, nextR, nextC);

  // No Possible Moves, Dead Solution
  if (nextDigit.empty() == true) return;

  // Try Each Possible Move
  for (int i = 0, __END = nextDigit.size(); i < __END; ++i) {
    board[nextR][nextC] = nextDigit[i];
    solveBoard(board, currSteps + 1);
    if (mSudokuSolved == true) return;
    board[nextR][nextC] = '.';
  }
}

void Solution::solveSudoku(vector<vector<char>>& board) noexcept {
  // Count Current Number of Steps
  int currSteps = 0;
  for (int R = 0; R < 9; ++R)
    for (int C = 0; C < 9; ++C)
      if (board[R][C] != '.') ++currSteps;

  // Runtime O()
  // Space O()
  solveBoard(board, currSteps);
}
