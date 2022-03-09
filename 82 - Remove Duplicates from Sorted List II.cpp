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
  static ListNode* deleteDuplicates(ListNode* head) noexcept {
    // Edge Case
    if (head == nullptr) return nullptr;

    // Variable Initialization
    int lastValue = INT_MIN;
    ListNode dummyHead(0, nullptr);
    ListNode* iHead = &dummyHead;
    ListNode* retAddress = &dummyHead;

    // Perform Algorithm
    while (head != nullptr) {
      int nextValue = head->next == nullptr ? INT_MIN : head->next->val;
      if (head->val != lastValue && head->val != nextValue)
        iHead->next = head, iHead = iHead->next, lastValue = head->val,
        head = head->next, iHead->next = nullptr;
      else
        lastValue = head->val, head = head->next;
    }

    // Runtime O(N)
    // Space O(1)
    return retAddress->next;
  }
};
