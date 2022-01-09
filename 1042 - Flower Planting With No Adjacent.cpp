#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) noexcept {
    // Initialization
    auto Map = new vector<uint16_t>[n];
    vector<int> Color(n, 0);
    for (const auto& i : paths)
      Map[i[0] - 1].push_back(i[1] - 1), Map[i[1] - 1].push_back(i[0] - 1);
    // Calculate Color
    for (uint16_t i = 0; i < n; ++i) {
      const auto& Node = Map[i];
      uint8_t PC[4] = {1, 2, 3, 4};
      for (const auto& i : Node) {
        if (Color[i] != 0) PC[Color[i] - 1] = 0;
        if (max(PC[0], max(PC[1], max(PC[2], PC[3]))) == 0) break;
      }
      Color[i] = max(PC[0], max(PC[1], max(PC[2], PC[3])));
    }
    // Yay!
    return Color;
  }
};

#if 0  // Does Not Work, Time Limits Exceeded
class Solution {
  unordered_set<int>* InDegree;
  uint8_t* Color;

 public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) noexcept {
    // Initialization
    InDegree = new unordered_set<int>[n];
    Color = new uint8_t[n]();
    for (const auto& V : paths)
      InDegree[V[0] - 1].insert(V[1] - 1), InDegree[V[1] - 1].insert(V[0] - 1);
    // Garden Planning
    int MaxIndegree = 0;
    queue<int> Q;
    for (int i = 0; i < n; ++i) {
      const auto size = InDegree[i].size();
      if (size > MaxIndegree) {
        MaxIndegree = size;
        Q = queue<int>{};
      }
      if (size == MaxIndegree) Q.push(i);
    };
    while (true) {
      const auto Curr = Q.front();
      Q.pop();
      int Ava[4] = {1, 2, 3, 4};
      for (const auto& N : InDegree[Curr])
        if (Color[N] != 0) Ava[Color[N] - 1] = 0;
      Color[Curr] = max(Ava[0], max(Ava[1], max(Ava[2], Ava[3])));

      // Next Level
      if (Q.empty()) {
        MaxIndegree = 0;
        for (int i = 0; i < n; ++i) {
          const auto size = InDegree[i].size();
          if (size > MaxIndegree) {
            MaxIndegree = size;
            Q = queue<int>{};
          }
          if (size == MaxIndegree) Q.push(i);
        };
        if (Q.size() == n) break;
      }
    }
    // Yay!
    return {&Color[0], &Color[n]};
  }
};
#endif
