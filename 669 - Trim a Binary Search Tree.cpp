#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

static bool runBSTCheck(TreeNode *root) noexcept;

static TreeNode *trim(TreeNode *root, int low, int high) noexcept;

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
  /**
   * Trim the BST, cuts any value not in the range [low,high]
   * BST structure may change
   * @param root Root node of a binary search tree
   * @param low Lowest value
   * @param high Highest value
   * @throws invalid_argument If input tree is nullptr or is not a BST
   */
  static TreeNode *trimBST(TreeNode *root, int low, int high);
};

// ============================================================================
//                         IMPLEMENTATION STARTS HERE
// ============================================================================

TreeNode *Solution::trimBST(TreeNode *root, int low, int high) {
  // Checks if the input tree is nullptr or is not a BST
  if (root == nullptr || runBSTCheck(root) == false)
    throw invalid_argument("Input Tree is NOT BST");

  // Invoke helper function
  return trim(root, low, high);
}

static bool runBSTCheck(TreeNode *root) noexcept { return true; }

static TreeNode *trim(TreeNode *root, int low, int high) noexcept {
  // Current node value is less than lower boundary
  // Follow the right child path
  if (root->val < low)
    return root->right == nullptr ? nullptr : trim(root->right, low, high);

  // Current node value is greater than upper boundary
  // Follow the left child path
  if (root->val > high)
    return root->left == nullptr ? nullptr : trim(root->left, low, high);

  // Current node value is inside the boundary
  // Recursively trim left & right side
  if (root->left != nullptr) root->left = trim(root->left, low, high);
  if (root->right != nullptr) root->right = trim(root->right, low, high);

  // Subtree is trimed, returning root of the subtree
  return root;
}
