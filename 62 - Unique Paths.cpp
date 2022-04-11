#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  static int runTopDown(const int m, const int n) noexcept;
  static int runButtomUp(const int m, const int n) noexcept;

 public:
  Solution() = default;
  static int uniquePaths(const int m, const int n) noexcept;
};

int Solution::runTopDown(const int m, const int n) noexcept {
  // Variable Initialization
  unique_ptr<int[]> p[m + 1];
  for (int i = 0; i < m + 1; ++i) p[i] = unique_ptr<int[]>(new int[n + 1]());

  //  Helper Function Implementation
  function<int(int, int)> runDFS = [&](const int x, const int y) {
    return p[x][y] > 0 ? p[x][y]
                       : p[x][y] = (x + 1 <= m ? runDFS(x + 1, y) : 0) +
                                   (y + 1 <= n ? runDFS(x, y + 1) : 0);
  };

  // Base Case
  p[m][n] = 1;

  // Top Down Dynamic Programming
  return runDFS(0, 0);
}

int Solution::runButtomUp(const int m, const int n) noexcept {
  // Variable Initialization
  unique_ptr<int[]> p[m + 1];
  for (int i = 0; i < m + 1; ++i) p[i] = unique_ptr<int[]>(new int[n + 1]());

  // Base Case
  p[m][n] = 1;

  // Buttom Up Dynamic Programming
  for (int x = m; x >= 0; --x)
    for (int y = n; y >= 0; --y)
      if (p[x][y] == 0)
        p[x][y] =
            (x + 1 <= m ? p[x + 1][y] : 0) + (y + 1 <= n ? p[x][y + 1] : 0);

  // Result Value
  return p[0][0];
}

int Solution::uniquePaths(const int m, const int n) noexcept {
  // Runtime O(M*N)
  // Space O(M*N)
  return runButtomUp(m - 1, n - 1);
}
