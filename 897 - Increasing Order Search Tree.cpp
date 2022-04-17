#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

static TreeNode *runDFS(TreeNode *listRoot, TreeNode *treeRoot);

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
  static TreeNode *increasingBST(TreeNode *root) noexcept;
};

TreeNode *Solution::increasingBST(TreeNode *root) noexcept {
  // Create dummy head node
  TreeNode dummyNode;

  // Invoke helper funtion
  runDFS(&dummyNode, root);

  return dummyNode.right;
}

static TreeNode *runDFS(TreeNode *listRoot, TreeNode *treeRoot) {
  // Add left tree to the listRoot
  if (treeRoot->left != nullptr) {
    listRoot = runDFS(listRoot, treeRoot->left);
    treeRoot->left = nullptr;
  }

  // Add current node to listRoot
  listRoot->right = treeRoot;
  listRoot = listRoot->right;

  // Add right tree to the listRoot
  if (treeRoot->right != nullptr) listRoot = runDFS(listRoot, treeRoot->right);

  return listRoot;
}
