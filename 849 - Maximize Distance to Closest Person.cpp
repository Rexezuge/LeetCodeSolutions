#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxDistToClosest(const vector<int>& seats) noexcept {
    const uint16_t n = seats.size();
    int16_t prev = -1, next = 0;
    uint16_t alex = 0;
    for (uint16_t i = 0; i < n; ++i) {
      if (seats[i] == 1)
        prev = i;
      else {
        if (next < i) next = i;
        while (next < n && seats[next] == 0) ++next;
        const uint16_t left = (prev < 0 ? n : i - prev);
        const uint16_t right = (next == n ? n : next - i);
        alex = max(alex, min(right, left));
      }
    }
    return alex;
  }
};
