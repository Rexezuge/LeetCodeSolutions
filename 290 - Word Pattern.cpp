#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool wordPattern(const string& pattern, const string& s) noexcept {
    stringstream SS(s);
    vector<string> Input;
    string Buffer;
    while (SS >> Buffer) Input.push_back(Buffer);
    if (pattern.size() != Input.size()) return false;
    auto WP = new string[26];
    unordered_map<string, char> HP;
    const uint8_t n = pattern.size();
    for (uint8_t i = 0; i < n; ++i) {
      const auto& Index = pattern[i] - 'a';
      auto T = HP.find(Input[i]);
      if (WP[Index].empty() && T == HP.end())
        WP[Index] = Input[i], HP[Input[i]] = pattern[i];
      else if (WP[Index] != Input[i] || T->second != pattern[i])
        return false;
    }
    return true;
  }
};
