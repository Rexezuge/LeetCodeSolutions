#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int calPoints(const vector<string>& ops) noexcept {
    // Variable Initialization
    vector<int> scoreRecord;

    // Run Simulation
    for (const string& s : ops) {
      if (s == "+")
        scoreRecord.push_back(scoreRecord[scoreRecord.size() - 1] +
                              scoreRecord[scoreRecord.size() - 2]);
      else if (s == "D")
        scoreRecord.push_back(scoreRecord.back() * 2);
      else if (s == "C")
        scoreRecord.pop_back();
      else
        scoreRecord.push_back(stoi(s));
    }

    // Runtime O(N)
    // Space O(N)
    return accumulate(scoreRecord.begin(), scoreRecord.end(), 0);
  }
};
