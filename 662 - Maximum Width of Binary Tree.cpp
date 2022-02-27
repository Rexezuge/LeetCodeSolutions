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
  static int widthOfBinaryTree(TreeNode *root) noexcept {
    // Edge Case
    if (root == nullptr) return 0;

    // Variable Initialization
    queue<pair<TreeNode *, int>> currQueue;
    int maxWidth = 1;

    // Starting Case
    currQueue.push({root, 1});

    // Perform the Algorithm
    while (!currQueue.empty()) {
      const int n = currQueue.size(), valStart = currQueue.front().second,
                valEnd = currQueue.back().second;
      maxWidth = max(maxWidth, valEnd - valStart + 1);
      for (int i = 0; i < n; ++i) {
        auto [node, idx] = currQueue.front();
        idx -= valStart;
        if (node->left != nullptr) currQueue.push({node->left, idx << 1});
        if (node->right != nullptr)
          currQueue.push({node->right, (idx << 1) + 1});
        currQueue.pop();
      }
    }

    // Time Complexity O(N)
    // Space Complexity O(N)
    return maxWidth;
  }
};
