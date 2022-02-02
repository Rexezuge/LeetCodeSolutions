#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<int> findAnagrams(string_view s, string_view p) noexcept {
    vector<int> Anagrams;

    unordered_map<char, int> pCount, sCount;
    for (auto i : p) ++pCount[i];

    const int size_s = s.size(), size_p = p.size();

    for (int i = 0; i < size_s; ++i) {
      ++sCount[s[i]];

      if (i < size_p - 1) continue;

      for (const auto& [K, V] : pCount)
        if (sCount[K] != V) goto __L_FAILED;

      Anagrams.push_back(i - size_p + 1);

    __L_FAILED:;

      --sCount[s[i - size_p + 1]];
    }

    return Anagrams;
  }
};
