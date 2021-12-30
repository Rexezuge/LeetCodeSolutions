#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& __N, int __V) {
    if (__N.empty()) {
      return 0;
    }
    int HEAD = 0, TAIL = __N.size();
    while (HEAD != TAIL) {
      if (__N[HEAD] == __V) {
        swap(__N[HEAD], __N[--TAIL]);
      } else {
        ++HEAD;
      }
    }
    return TAIL;
  }
};
