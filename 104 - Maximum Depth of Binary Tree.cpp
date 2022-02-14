#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  static int maxDepth(TreeNode *root) noexcept {
    function<int(TreeNode *)> DFS = [&](TreeNode *iTR) {
      if (iTR == nullptr) return 0;
      return max(DFS(iTR->left), DFS(iTR->right)) + 1;
    };
    return DFS(root);
  }
};
