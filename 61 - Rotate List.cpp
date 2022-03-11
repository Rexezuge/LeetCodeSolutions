#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  static ListNode* rotateRight(ListNode* head, int k) noexcept {
    // Edge Case
    if (head == nullptr) return nullptr;

    // Variable Initialization
    vector<ListNode*> listVec;

    // Store Elements in the Vector
    while (head != nullptr) listVec.push_back(head), head = head->next;

    // Sanity Check
    k = k % listVec.size();
    if (k == 0) return listVec.front();

    // Rotate the Vector
    rotate(listVec.begin(), listVec.end() - k, listVec.end());

    // Link the Vector
    listVec[k - 1]->next = listVec[k];
    listVec.back()->next = nullptr;

    // Runtime O(N)
    // Space O(N)
    return listVec.front();
  }
};
