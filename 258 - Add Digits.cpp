#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int addDigits(int num) noexcept {
    if (num == 0) return 0;
    if (num % 9 == 0) return 9;
    return num % 9;
  }
};

#if 0  // Works, Recursion
class Solution {
 public:
  static int addDigits(int num) noexcept {
    int Result = 0;
    while (num > 0) {
      Result += num % 10;
      num = num / 10;
    }
    return Result < 10 ? Result : addDigits(Result);
  }
};
#endif
