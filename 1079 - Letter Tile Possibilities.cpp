#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_set<string> P;

  void Recursion(string& tiles) noexcept {
    // Initailization
    uint8_t size = tiles.size();
    sort(tiles.begin(), tiles.end());
    // Find Possibilities
    do
      P.insert(tiles);
    while (next_permutation(tiles.begin(), tiles.end()));
    // Recursion
    for (uint8_t i = 0; i < size; ++i) {
      if (i > 0 && tiles[i] == tiles[i - 1]) continue;
      string T = tiles.substr(0, i);
      T += tiles.substr(i + 1);
      if (!T.empty()) this->Recursion(T);
    }
  }

 public:
  int numTilePossibilities(string& tiles) noexcept {
    this->Recursion(tiles);
    return P.size();
  }
};
