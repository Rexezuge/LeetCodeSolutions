#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int minDominoRotations(const vector<int>& tops,
                                const vector<int>& bottoms) noexcept {
    // Variable Initialization
    unique_ptr<int[]> appearedTop(new int[7]()), appearedBottom(new int[7]()),
        appearedBoth(new int[7]());
    int retVal = INT_MAX;

    // Count Number of Occurrences
    for (int i = 0, __END = tops.size(); i < __END; ++i) {
      ++appearedTop[tops[i]], ++appearedBottom[bottoms[i]];
      if (tops[i] == bottoms[i]) ++appearedBoth[tops[i]];
    }

    // Find Minimum Rotations
    for (int i = 1; i <= 6; ++i)
      if (appearedTop[i] + (appearedBottom[i] - appearedBoth[i]) == tops.size())
        retVal = min(retVal,
                     min(appearedTop[i], appearedBottom[i]) - appearedBoth[i]);

    return retVal == INT_MAX ? -1 : retVal;
  }
};
