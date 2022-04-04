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
  static int getLength(ListNode* head) noexcept {
    int listLength = 0;
    while (head != nullptr) {
      ++listLength;
      head = head->next;
    }
    return listLength;
  }

 public:
  static ListNode* swapNodes(ListNode* const head, int k) noexcept {
    // Variable Initialization
    const int listLength = getLength(head);
    ListNode *firstK = head, *secondK = head;

    // Iterate to the Correct Location
    for (int i = 0; i < k - 1; ++i) firstK = firstK->next;
    for (int i = 0; i < listLength - k; ++i) secondK = secondK->next;

    // Swap Value
    swap(firstK->val, secondK->val);

    // Runtime O(N)
    // Space O(1)
    return head;
  }
};
