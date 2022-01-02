#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numPairsDivisibleBy60(const vector<int>& __time) const noexcept {
    int* Remainder = new int[60]();
    int Result = 0;
    for (int i = 0, __LOOP_SIZE = __time.size(); i < __LOOP_SIZE; ++i) {
      Result += Remainder[(60 - __time[i] % 60) % 60];
      ++Remainder[__time[i] % 60];
    }
    return Result;
  }
};

#if 0  // Work, But Slow
class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& __time) {
    int Result = 0;
    unordered_multiset<int> HashTable;
    for (int i = 0; i < __time.size(); ++i) {
      for (int Sixes = 60; Sixes <= 1000; Sixes += 60) {
        Sixes - __time[i] % 60 ? Result += HashTable.count(Sixes - __time[i])
                               : Result += HashTable.count(Sixes);
      }
      HashTable.insert(__time[i]);
    }
    return Result;
  }
};
#endif
