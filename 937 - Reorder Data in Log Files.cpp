#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> reorderLogFiles(vector<string>& logs) noexcept {
    // Initialization
    vector<string> Letters;
    vector<string> Digits;
    uint8_t size = logs.size();
    Letters.reserve(size / 2);
    Digits.reserve(size / 2);
    // Reorder
    for (uint8_t i = 0; i < size; ++i)
      if (isalpha(logs[i].back()))
        Letters.push_back(move(logs[i]));
      else
        Digits.push_back(move(logs[i]));
    sort(Letters.begin(), Letters.end(), [&](const auto& lhs, const auto& rhs) {
      // Initialization
      uint8_t id1 = lhs.find(' '), id2 = rhs.find(' ');
      uint8_t size = min(lhs.size() - id1, rhs.size() - id2);
      // Compare
      for (uint8_t i = id1 + 1, j = id2 + 1; i <= size && j <= size; ++i, ++j)
        if (lhs[i] != rhs[j]) return lhs[i] < rhs[j];
      if (lhs.size() - id1 != rhs.size() - id2)
        return lhs.size() - id1 < rhs.size() - id2;
      return lhs.substr(0, id1) < rhs.substr(0, id2);
    });
    // Yay!
    Letters.insert(Letters.end(), Digits.begin(), Digits.end());
    return Letters;
  }
};
