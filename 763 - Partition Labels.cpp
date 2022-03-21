#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<int> partitionLabels(string_view s) noexcept {
    // Variable Initialization
    unique_ptr<int[]> lastIdx(new int[26]());
    vector<int> retVal;

    // Scan Though Input String &
    // Record Last Appeared Index
    for (int i = 0, __END = s.size(); i < __END; ++i) lastIdx[s[i] - 'a'] = i;

    // Add Segment to Result
    for (int i = 0, __END = s.size(), leftIdx = 0, rightIdx = 0; i < __END;
         ++i) {
      rightIdx = max(rightIdx, lastIdx[s[i] - 'a']);
      if (i == rightIdx) {
        retVal.push_back(rightIdx - leftIdx + 1);
        leftIdx = rightIdx + 1;
      }
    }

    // Runtime O(N)
    // Space O(1)
    return retVal;
  }
};
