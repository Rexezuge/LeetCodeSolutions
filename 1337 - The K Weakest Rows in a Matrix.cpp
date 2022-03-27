#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<int> kWeakestRows(const vector<vector<int>>& mat,
                                  int k) noexcept {
    // Variable Initialization
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   function<bool(pair<int, int>, pair<int, int>)>>
        sortMatrix([](const pair<int, int>& A, const pair<int, int>& B) {
          if (A.second != B.second) return A.second > B.second;
          return A.first > B.first;
        });
    vector<int> retVal;

    // Populate the Data Structure
    int matIdx = 0;
    for (const auto& matRow : mat) {
      int numSoldiers = 0;
      for (const auto& matCol : matRow) {
        if (matCol == 0) break;
        ++numSoldiers;
      }
      sortMatrix.push({matIdx, numSoldiers});
      ++matIdx;
    }

    // Find K Weakest Rows
    while (k > 0) {
      retVal.push_back(sortMatrix.top().first);
      sortMatrix.pop();
      --k;
    }

    // Runtime O(M*N)
    // Space O(M);
    return retVal;
  }
};
