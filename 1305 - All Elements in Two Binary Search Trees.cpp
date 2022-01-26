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
  void DFS(vector<int> &Q, const TreeNode *const root) noexcept {
    if (root == nullptr) return;
    DFS(Q, root->left);
    Q.push_back(root->val);
    DFS(Q, root->right);
  }

 public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) noexcept {
    vector<int> Q1, Q2;
    DFS(Q1, root1);
    DFS(Q2, root2);

    vector<int> Result;
    Result.reserve(Q1.size() + Q2.size());

    uint16_t iX1 = 0, iX2 = 0;
    const uint16_t n1 = Q1.size(), n2 = Q2.size();
    while (true) {
      if (iX1 == n1) {
        Result.insert(Result.end(), Q2.begin() + iX2, Q2.end());
        break;
      } else if (iX2 == n2) {
        Result.insert(Result.end(), Q1.begin() + iX1, Q1.end());
        break;
      } else {
        if (Q1[iX1] < Q2[iX2]) {
          Result.push_back(Q1[iX1]);
          ++iX1;
        } else {
          Result.push_back(Q2[iX2]);
          ++iX2;
        }
      }
    }
    return Result;
  }
};
