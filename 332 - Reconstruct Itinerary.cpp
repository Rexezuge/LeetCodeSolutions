#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<string> findItinerary(
      vector<vector<string>>& Tickets) noexcept {
    sort(Tickets.begin(), Tickets.end(), [&](const auto& A, const auto& B) {
      return (A[0] != B[0]) ? (A[0] < B[0]) : (A[1] < B[1]);
    });

    vector<string> Result;

    unordered_map<string_view, vector<pair<string_view, bool>>> AdjList;

    for (const auto& Vec : Tickets) AdjList[Vec[0]].push_back({Vec[1], true});

    bool isComplete = false;
    const int ExpectedSize = Tickets.size() + 1;
    function<void(string_view)> DFS = [&](string_view Name) {
      if (isComplete) return;

      auto& Adj = AdjList[Name];

      Result.push_back(string(Name));

      for (auto& P : Adj) {
        if (P.second == false) continue;

        P.second = false;
        DFS(P.first);
        P.second = true;
      }

      if (Result.size() == ExpectedSize)
        isComplete = true;
      else
        Result.pop_back();
    };

    DFS("JFK");

    return Result;
  }
};
