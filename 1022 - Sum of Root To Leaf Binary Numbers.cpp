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
  int sumRootToLeaf(TreeNode *root, int sum = 0) {
    return !root->left && !root->right
               ? sum * 2 + root->val
               : ((root->left ? sumRootToLeaf(root->left, sum * 2 + root->val)
                              : 0) +
                  (root->right ? sumRootToLeaf(root->right, sum * 2 + root->val)
                               : 0));
  }
};
