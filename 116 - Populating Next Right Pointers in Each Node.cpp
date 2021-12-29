#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* _ROOT) {
    if (!_ROOT) {
      return nullptr;
    }
    vector<Node*> CURRENT_LEVEL;
    vector<Node*> NEXT_LEVEL;
    CURRENT_LEVEL.push_back(_ROOT);
    while (!CURRENT_LEVEL.empty()) {
      for (size_t i = 0;; ++i) {
        if (CURRENT_LEVEL[i]->left) {
          NEXT_LEVEL.push_back(CURRENT_LEVEL[i]->left);
          NEXT_LEVEL.push_back(CURRENT_LEVEL[i]->right);
        }
        if (i < CURRENT_LEVEL.size() - 1) {
          CURRENT_LEVEL[i]->next = CURRENT_LEVEL[i + 1];
        } else if (i == CURRENT_LEVEL.size() - 1) {
          CURRENT_LEVEL = NEXT_LEVEL;
          NEXT_LEVEL.clear();
          break;
        }
      }
    }
    return _ROOT;
  }
};
