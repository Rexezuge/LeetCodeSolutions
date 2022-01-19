#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) noexcept {
    auto slow = head, fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        slow = head;
        while (slow != fast) slow = slow->next, fast = fast->next;
        return slow;
      }
    }
    return nullptr;
  }
};

#if 0  // Works, Using HashMap
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> M;
    while (true) {
      if (M.insert(head).second == false) return head;
      head = head->next;
    }
    return nullptr;
  }
};
#endif
