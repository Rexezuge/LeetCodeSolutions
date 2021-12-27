#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& N) {
    if (N.size() < 2) {
      return {};
    }
    sort(N.begin(), N.end());
    vector<vector<int>> R;
    for (size_t i = 0; i < N.size() - 2; ++i) {
      if (i > 0 && N[i - 1] == N[i]) {
        continue;
      }
      const int& DIFF = -N[i];
      size_t HEAD = i + 1, TAIL = N.size() - 1;
      while (HEAD < TAIL) {
        if (N[HEAD] + N[TAIL] == DIFF) {
          R.push_back({N[i], N[HEAD], N[TAIL]});
          ++HEAD;
        }
        if (N[HEAD] + N[TAIL] < DIFF) {
          do {
            ++HEAD;
          } while (N[HEAD] == N[HEAD - 1] && HEAD < TAIL);
        } else {
          do {
            --TAIL;
          } while (N[TAIL] == N[TAIL + 1] && TAIL > HEAD);
        }
      }
    }
    return R;
  }
};
