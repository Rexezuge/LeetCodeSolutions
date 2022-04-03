#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
  static constexpr char EMPTY_NODE[] = "-1111";
  static constexpr int EMPTY_NODE_INT = -1111;

 public:
  static string serialize(TreeNode* root) noexcept;
  static TreeNode* deserialize(const string& data) noexcept;
};

string Codec::serialize(TreeNode* root) noexcept {
  // Variable Initialization
  string retVal;
  queue<TreeNode*> bfsQueue;

  // Begin Case
  bfsQueue.push(root);

  // Perform BFS
  while (!bfsQueue.empty()) {
    TreeNode* n = bfsQueue.front();
    bfsQueue.pop();
    // Push Value to String
    if (n == nullptr) {
      retVal += EMPTY_NODE;
    } else {
      retVal += to_string(n->val);
      // Add Child to Queue
      bfsQueue.push(n->left);
      bfsQueue.push(n->right);
    }
    retVal.push_back(' ');
  }

  // Remove Extra Space
  retVal.pop_back();

  // Runtime O(N)
  // Space O(N)
  return retVal;
}

TreeNode* Codec::deserialize(const string& data) noexcept {
  // Edge Case
  if (data == EMPTY_NODE) return nullptr;

  // Variable Initialization
  stringstream ss(data);
  int nodeLeft, nodeRight;
  queue<TreeNode*> dfsQueue;

  // Populate the Initial Value
  ss >> nodeLeft;
  TreeNode* root = new TreeNode(nodeLeft);
  dfsQueue.push(root);

  // Parse String
  while (ss >> nodeLeft >> nodeRight) {
    // Push Current Node
    TreeNode* n = dfsQueue.front();
    dfsQueue.pop();
    // Push Left Child
    if (nodeLeft != EMPTY_NODE_INT) {
      n->left = new TreeNode(nodeLeft);
      dfsQueue.push(n->left);
    }
    // Push Right Child
    if (nodeRight != EMPTY_NODE_INT) {
      n->right = new TreeNode(nodeRight);
      dfsQueue.push(n->right);
    }
  }

  // Runtime O(N)
  // Space O(N)
  return root;
}
