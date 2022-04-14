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
  static TreeNode *searchBST(TreeNode *root, int val,
                             TreeNode *retVal = nullptr) noexcept {
    return root == nullptr
               ? nullptr
               : (root->val == val
                      ? root
                      : (root->val > val ? searchBST(root->left, val)
                                         : searchBST(root->right, val)));
  }
};
