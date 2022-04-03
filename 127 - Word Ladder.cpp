#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  static bool diffByOne(const string& a, const string& b) noexcept {
    int diffLetters = 0;
    for (int i = 0, __END = a.size(); i < __END; ++i)
      if (a[i] != b[i]) ++diffLetters;
    return diffLetters == 1;
  }

 public:
  static int ladderLength(const string& beginWord, const string& endWord,
                          const vector<string>& wordList) noexcept {
    // Create Graph
    unordered_map<string, vector<string>> wordGraph;
    for (const string& s : wordList) {
      wordGraph.insert({s, {}});
      for (auto& [k, v] : wordGraph)
        if (diffByOne(s, k)) v.push_back(s), wordGraph[s].push_back(k);
    }

    // beginWord NOT in Graph
    if (wordGraph.count(beginWord) == 0) {
      wordGraph.insert({beginWord, {}});
      for (auto& [k, v] : wordGraph)
        if (diffByOne(beginWord, k))
          v.push_back(beginWord), wordGraph[beginWord].push_back(k);
    }

    // Perform BFS Algorithm
    unordered_set<string> visitedNode;
    queue<pair<string, int>> bfsQueue;
    bfsQueue.push({beginWord, 1});
    visitedNode.insert(beginWord);
    while (!bfsQueue.empty()) {
      const auto [s, v] = bfsQueue.front();
      bfsQueue.pop();
      if (s == endWord) return v;
      for (const string& i : wordGraph[s]) {
        if (visitedNode.count(i) > 0) continue;
        visitedNode.insert(i);
        bfsQueue.push({i, v + 1});
      }
    }

    // Runtime O(N*N)
    // Space O(N*N)
    return 0;
  }
};
