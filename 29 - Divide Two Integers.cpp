#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int divide(long __dividend, long __divisor) {
    if (__dividend == INT_MIN && __divisor == -1) return INT_MAX;
    int sign = 1;
    if (__divisor < 0) {
      __divisor = -1 * __divisor;
      sign = -1 * sign;
    }
    if (__dividend < 0) {
      __dividend = -1 * __dividend;
      sign = -1 * sign;
    }
    long result = 0;
    __dividend = labs(__dividend);
    __divisor = labs(__divisor);
    while (__dividend >= __divisor) {
      long t = __divisor;
      int r = 1;
      while (__dividend >= t << 1) {
        t = t << 1;
        r = r << 1;
      }
      __dividend -= t;
      result += r;
    }
    return result * sign;
  }
};
