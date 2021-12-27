#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& N, int TARGET) {
    int BEST = INT_MAX;
    sort(N.begin(), N.end());
    for (size_t i = 0; i < N.size() - 2; ++i) {
      if (i > 0 && N[i - 1] == N[i]) {
        continue;
      }
      size_t HEAD = i + 1, TAIL = N.size() - 1;
      while (HEAD < TAIL) {
        const int& SUM = N[i] + N[HEAD] + N[TAIL];
        if (SUM == TARGET) {
          return TARGET;
        }
        if (SUM < TARGET) {
          if (abs(TARGET - SUM) < abs(TARGET - BEST)) {
            BEST = SUM;
          }
          do {
            ++HEAD;
          } while (N[HEAD] == N[HEAD - 1] && HEAD < TAIL);
        } else {
          if (abs(TARGET - SUM) < abs(TARGET - BEST)) {
            BEST = SUM;
          }
          do {
            --TAIL;
          } while (N[TAIL] == N[TAIL + 1] && TAIL > HEAD);
        }
      }
    }
    return BEST;
  }
};
