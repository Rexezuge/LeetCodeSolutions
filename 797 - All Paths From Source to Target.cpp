#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(
      const vector<vector<int>>& graph) const noexcept {
    const uint8_t n = graph.size();
    const uint8_t destination = n - 1;
    vector<vector<int>> Result;

    vector<int> CurrentPath;

    function<void(int)> DFS = [&](uint8_t vertex) {
      CurrentPath.push_back(vertex);

      if (vertex == destination) Result.push_back(CurrentPath);

      for (const auto& i : graph[vertex]) DFS(i);

      CurrentPath.pop_back();
    };

    DFS(0);

    return Result;
  }
};
