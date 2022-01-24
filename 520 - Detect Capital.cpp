#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool detectCapitalUse(const string& word) noexcept {
    return regex_match(word, regex("[A-Z]*|.[a-z]*"));
  }
};
