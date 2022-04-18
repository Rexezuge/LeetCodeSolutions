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
  static int findKthSmallest(TreeNode *root, int k) noexcept {
    if (root == nullptr)
      // Empty Node
      return 0;

    // Search Left Sub Tree
    int leftDepth = findKthSmallest(root->left, k);
    if (leftDepth < 0)
      // Returning Result
      return leftDepth;

    // Search Current Node
    if (k == 0 || leftDepth + 1 == k)
      // Result Found
      return -root->val - 1;

    // Search Right Sub Tree
    int rightDepth = findKthSmallest(root->right, k - leftDepth - 1);
    if (rightDepth < 0)
      // Returning Result
      return rightDepth;

    // Return Current Depth
    return leftDepth + rightDepth + 1;
  }

 public:
  static int kthSmallest(TreeNode *root, int k) noexcept {
    return -findKthSmallest(root, k) - 1;
  }
};
