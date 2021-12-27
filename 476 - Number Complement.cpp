#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findComplement(int& num) {
    int RESULT = 0;
    bool isFirst = true;
    for (int i = 1 << 30; i > 0; i = i >> 1) {
      if ((num & i) != 0) {
        if (isFirst) {  // Bits == 1
          isFirst = !isFirst;
        }
      } else {  // Bits == 0
        if (!isFirst) {
          RESULT += i;
        }
      }
    }
    return RESULT;
  }
};
