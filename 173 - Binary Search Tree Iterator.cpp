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

class BSTIterator {
  unique_ptr<stack<TreeNode *>> nodeParents;

  void pushLeftSubTree(TreeNode *root) noexcept;

 public:
  BSTIterator() = delete;

  explicit BSTIterator(TreeNode *root) noexcept;

  int next() noexcept;

  bool hasNext() noexcept;
};

void BSTIterator::pushLeftSubTree(TreeNode *root) noexcept {
  while (root != nullptr) {
    nodeParents->push(root);
    root = root->left;
  }
}

BSTIterator::BSTIterator(TreeNode *root) noexcept
    : nodeParents(new stack<TreeNode *>) {
  pushLeftSubTree(root);
}

int BSTIterator::next() noexcept {
  TreeNode *n = nodeParents->top();
  nodeParents->pop();
  if (n->right != nullptr) pushLeftSubTree(n->right);
  return n->val;
}

bool BSTIterator::hasNext() noexcept { return !nodeParents->empty(); }
