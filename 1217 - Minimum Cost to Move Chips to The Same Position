#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCostToMoveChips(vector<int>& position) {
    uint8_t ODD = 0, EVEN = 0;
    for (const auto& i : position) {
      i % 2 == 1 ? ++ODD : ++EVEN;
    }
    return min(ODD, EVEN);
  }
};
