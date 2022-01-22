#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> Squares;
  int Size;
  unordered_map<int, bool> Memory;

  bool DFS(int n) {
    auto iTR = Memory.find(n);
    if (iTR != Memory.end()) return iTR->second;
    for (int i = 0; i < Size && Squares[i] <= n; ++i) {
      if (DFS(n - Squares[i]) == false) {
        Memory.insert({n, true});
        return true;
      }
    }
    Memory.insert({n, false});
    return false;
  }

 public:
  bool winnerSquareGame(int n) {
    for (int i = 1; i * i <= n; ++i) Squares.push_back(i * i);
    Size = Squares.size();
    Memory.insert({0, false});
    return DFS(n);
  }
};
