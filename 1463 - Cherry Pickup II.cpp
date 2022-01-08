#include <bits/stdc++.h>
using namespace std;

class Solution {
  size_t X_Max, Y_Max;
  const vector<vector<int>>* grid;
  int*** Memory;

  bool InRange(int x, int y) const noexcept {
    return x >= 0 && x < this->X_Max && y >= 0 && y < this->Y_Max;
  }

  int Recursion(int x, int y1, int y2) noexcept {
    // Base Case
    if (!InRange(x, y1) || !InRange(x, y2)) return 0;
    // Check Memory
    if (Memory[x][y1][y2] != -1) return Memory[x][y1][y2];
    // Initilization
    int MaxCherry = 0;
    int CurrentCell = (*grid)[x][y1];
    if (y1 != y2) CurrentCell += (*grid)[x][y2];
    // Recursion
    for (int8_t Case = 0; Case < 9; ++Case) {
      if (Case == 0)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 - 1, y2 - 1));
      else if (Case == 1)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 - 1, y2));
      else if (Case == 2)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 - 1, y2 + 1));
      else if (Case == 3)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1, y2 - 1));
      else if (Case == 4)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1, y2));
      else if (Case == 5)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1, y2 + 1));
      else if (Case == 6)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 + 1, y2 - 1));
      else if (Case == 7)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 + 1, y2));
      else if (Case == 8)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 + 1, y2 + 1));
    }
    // Yay!
    Memory[x][y1][y2] = MaxCherry + CurrentCell;
    return MaxCherry + CurrentCell;
  }

 public:
  int cherryPickup(const vector<vector<int>>& grid) {
    // Initilization
    this->X_Max = grid.size();
    this->Y_Max = grid[0].size();
    this->grid = &grid;
    this->Memory = new int**[X_Max];
    for (int i = 0; i < X_Max; ++i) {
      this->Memory[i] = new int*[Y_Max];
      for (int iR = 0; iR < Y_Max; ++iR) this->Memory[i][iR] = new int[Y_Max];
    }
    for (int i = 0; i < X_Max; ++i)
      for (int iR = 0; iR < Y_Max; ++iR)
        for (int iT = 0; iT < Y_Max; ++iT) Memory[i][iR][iT] = -1;
    // Yay!
    return this->Recursion(0, 0, grid[0].size() - 1);
  }
};

#if 0  // Works, Time Limit Exceeded
#include <bits/stdc++.h>
using namespace std;

class Solution {
  size_t X_Max, Y_Max;
  const vector<vector<int>>* grid;
  vector<pair<int, int>> R1, R2;

  bool InRange(int x, int y) const noexcept {
    return x >= 0 && x < this->X_Max && y >= 0 && y < this->Y_Max;
  }

  int CalcSum() const noexcept {
    // Base Case
    if (R1.size() < grid->size()) return 0;
    // Initilization
    int Result = 0;
    // Calculation
    for (size_t i = 0; i < R1.size(); ++i) {
      Result += (*grid)[R1[i].first][R1[i].second];
      if (R1[i] != R2[i]) Result += (*grid)[R2[i].first][R2[i].second];
    }
    // Yay!
    return Result;
  }

  int Recursion(int x, int y1, int y2) noexcept {
    // Base Case
    if (!InRange(x, y1) || !InRange(x, y2)) return CalcSum();
    // Initilization
    R1.push_back({x, y1});
    R2.push_back({x, y2});
    int MaxCherry = 0;
    // Recursion
    for (int8_t Case = 0; Case < 9; ++Case) {
      if (Case == 0)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 - 1, y2 - 1));
      else if (Case == 1)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 - 1, y2));
      else if (Case == 2)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 - 1, y2 + 1));
      else if (Case == 3)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1, y2 - 1));
      else if (Case == 4)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1, y2));
      else if (Case == 5)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1, y2 + 1));
      else if (Case == 6)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 + 1, y2 - 1));
      else if (Case == 7)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 + 1, y2));
      else if (Case == 8)
        MaxCherry = max(MaxCherry, this->Recursion(x + 1, y1 + 1, y2 + 1));
    }
    // Yay!
    R1.pop_back();
    R2.pop_back();
    return MaxCherry;
  }

 public:
  int cherryPickup(const vector<vector<int>>& grid) {
    // Initilization
    this->X_Max = grid.size();
    this->Y_Max = grid[0].size();
    this->R1.reserve(max(this->X_Max, this->Y_Max));
    this->R2.reserve(max(this->X_Max, this->Y_Max));
    this->grid = &grid;
    // Yay!
    return this->Recursion(0, 0, grid[0].size() - 1);
  }
};
#endif
