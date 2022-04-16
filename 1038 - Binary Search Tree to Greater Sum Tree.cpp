#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

static int convertBST_runDFS(TreeNode *root, int carry) noexcept;
static int convertBST_runDFS_OneLiner(TreeNode *root, int carry) noexcept;

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
  static TreeNode *bstToGst(TreeNode *root) noexcept;
};

TreeNode *Solution::bstToGst(TreeNode *root) noexcept {
  // Sanity check
  if (root == nullptr) return nullptr;

  // Invoke helper function
  convertBST_runDFS_OneLiner(root, 0);

  return root;
}

static int convertBST_runDFS(TreeNode *root, int carry) noexcept {
  // Get the sum of right hand tree
  int rightSum =
      root->right == nullptr ? carry : convertBST_runDFS(root->right, carry);

  // Increment current node
  root->val += rightSum;

  // Get the sum of left hand tree,
  // Left hand tree is always smaller than current node
  int leftSum = root->left == nullptr
                    ? root->val
                    : convertBST_runDFS(root->left, root->val);

  return leftSum;
}

static int convertBST_runDFS_OneLiner(TreeNode *root, int carry) noexcept {
  return root->left == nullptr
             ? (root->val += root->right == nullptr
                                 ? carry
                                 : convertBST_runDFS(root->right, carry))
             : convertBST_runDFS(
                   root->left,
                   (root->val += root->right == nullptr
                                     ? carry
                                     : convertBST_runDFS(root->right, carry)));
}
