#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& N, int target) {
    int HEAD = 0, TAIL = N.size() - 1;
    while (true) {
      if (N[HEAD] + N[TAIL] == target) {
        return vector<int>{HEAD + 1, TAIL + 1};
      }
      if (N[HEAD] + N[TAIL] < target) {
        ++HEAD;
      } else {
        --TAIL;
      }
    }
  }
};
