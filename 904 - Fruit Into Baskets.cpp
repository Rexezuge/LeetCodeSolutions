#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    // Initilization
    unordered_map<int, int> M;
    int Begin = 0, End = 0, Distinct = 0, Result = 0;
    // Sliding Window
    for (; End < fruits.size(); ++End) {
      if (M[fruits[End]] == 0) ++Distinct;
      ++M[fruits[End]];
      if (Distinct <= 2)
        Result = max(Result, End - Begin + 1);
      else {
        --M[fruits[Begin]];
        if (M[fruits[Begin]] == 0) --Distinct;
        ++Begin;
      }
    }
    // Yay!
    return Result;
  }
};
