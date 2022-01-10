#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string addBinary(const string &a, const string &b) const noexcept {
    const uint16_t size = max(a.size(), b.size()), a_size = a.size(),
                   b_size = b.size();
    char Carry = '0';
    string Result;
    Result.reserve(size + 1);
    for (int16_t i = 1; i <= size; ++i) {
      const char Left = i <= a_size ? a[a_size - i] : '0',
                 Right = i <= b_size ? b[b_size - i] : '0';
      const char Sum = Left + Right - '0';
      switch (Sum) {
        case '0':
          Result.push_back(Carry);
          Carry = '0';
          break;
        case '1':
          if (Carry == '0')
            Result.push_back('1');
          else
            Result.push_back('0');
          break;
        case '2':
          Result.push_back(Carry);
          Carry = '1';
          break;
      }
    }
    if (Carry == '1') Result.push_back(Carry);
    reverse(Result.begin(), Result.end());
    return Result;
  }
};
