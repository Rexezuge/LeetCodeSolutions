#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
  unordered_map<int, Node*> Visited;

 public:
  Node* cloneGraph(Node* root) noexcept {
    if (root == nullptr) return nullptr;

    const int Value = root->val;

    if (Visited.count(Value) > 0) return Visited[Value];

    Node* Result = new Node(Value);

    Visited.insert({Value, Result});

    const int n = root->neighbors.size();
    for (int i = 0; i < n; ++i)
      Result->neighbors.push_back(cloneGraph(root->neighbors[i]));

    return Result;
  }
};
