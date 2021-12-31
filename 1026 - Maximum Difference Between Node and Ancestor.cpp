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
  int maxAncestorDiff(TreeNode *__root, int __max = 0, int __min = INT_MAX) {
    int max = std::max(__max, __root->val), min = std::min(__min, __root->val);
    // Base Case
    if (!__root->left && !__root->right) {
      return max - min;
    }
    // Recursion & Merge
    return std::max(
        __root->left ? this->maxAncestorDiff(__root->left, max, min) : 0,
        __root->right ? this->maxAncestorDiff(__root->right, max, min) : 0);
  }
};

#if 0  // Uses Too Much Resources
class Solution {
 private:
  int Recursion(TreeNode *__root, vector<int> &&__vals) {
    if (!__root->left && !__root->right) {
      __vals.push_back(__root->val);
      int max = 0;
      for (size_t R = 0; R < __vals.size() - 1; ++R) {
        for (size_t C = R + 1; C < __vals.size(); ++C) {
          max = std::max(max, abs(__vals[R] - __vals[C]));
        }
      }
      return max;
    }
    int left_val = 0, right_val = 0;
    if (__root->left) {
      auto left_vec{__vals};
      left_vec.push_back(__root->val);
      left_val = this->Recursion(__root->left, move(left_vec));
    }
    if (__root->right) {
      auto right_vec{__vals};
      right_vec.push_back(__root->val);
      right_val = this->Recursion(__root->right, move(right_vec));
    }
    return max(left_val, right_val);
  }

 public:
  int maxAncestorDiff(TreeNode *__root) { return this->Recursion(__root, {}); }
};
#endif
