#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n < 0) return false;
    int OneAppeared = 0;
    bitset<sizeof(int) * 8> Bits(n);
    for (int i = 0; i < Bits.size(); ++i) {
      if (Bits[i] == 1) ++OneAppeared;
    }
    return OneAppeared == 1;
  }
};

#if 0  // Works, 0 ms CPU
// Ref: https://www.geeksforgeeks.org/binary-representation-of-a-given-number/
class Solution {
 public:
  bool isPowerOfTwo(int &n) {
    if (n < 0) {
      return false;
    }
    uint8_t ONE_APPEARED = 0;
    for (long i = 1 << 30; i > 0; i = i >> 1) {
      if ((n & i) != 0) {  // BIT == 1
        ++ONE_APPEARED;
      }
    }
    return ONE_APPEARED == 1;
  }
};
#endif
