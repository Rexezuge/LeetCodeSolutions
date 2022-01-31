#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool validPath(int n, const vector<vector<int>>& edges, int source,
                 int destination) const noexcept {
    auto Graph = new vector<int>[n];

    for (const auto& E : edges)
      Graph[E[0]].push_back(E[1]), Graph[E[1]].push_back(E[0]);

    auto Visited = new bool[n]();
    bool Result = false;

    function<void(int)> DFS = [&](int vertex) {
      if (Visited[vertex] == true) return;
      if (Result == true) return;
      if (vertex == destination) Result = true;

      Visited[vertex] = true;

      for (const auto& i : Graph[vertex]) DFS(i);
    };

    DFS(source);

    return Result;
  }
};
