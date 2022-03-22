#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static string getSmallestString(int n, int k) noexcept {
    // Variable Initialization
    string retVal(n, 'a');

    // Push Largest Letter into Result
    k -= n;
    while (k > 0) retVal[--n] += min(25, k), k -= min(25, k);

    // Runtime O(N)
    // Space O(1)
    return retVal;
  }
};

#if 0  // Works, Used std::reverse
class Solution {
 public:
  static string getSmallestString(int n, int k) noexcept {
    // Variable Initialization
    string retVal;

    // Push Largest Letter into Result
    while (k > n - retVal.size()) {
      int currDifference = k - n + retVal.size();
      if (currDifference >= 26) {
        retVal.push_back('z');
        k -= 26;
      } else {
        retVal.push_back('a' + currDifference);
        break;
      }
    }

    // Fill Result with 'a'
    while (retVal.size() < n) retVal.push_back('a');

    // Reverse Result
    reverse(retVal.begin(), retVal.end());

    // Runtime O(NlogN)
    // Space O(1)
    return retVal;
  }
};
#endif
