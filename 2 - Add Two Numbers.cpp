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
  static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) noexcept {
    // Recursion Function Declaration
    static const function<ListNode*(ListNode*, ListNode*, int)> runRecursion =
        [&](ListNode* leftNode, ListNode* rightNode, int carryVal) {
          if (leftNode == nullptr && rightNode == nullptr)
            return carryVal == 0 ? static_cast<ListNode*>(nullptr)
                                 : new ListNode(carryVal);
          return new ListNode(
              ((leftNode == nullptr ? 0 : leftNode->val) +
               (rightNode == nullptr ? 0 : rightNode->val) + carryVal) %
                  10,
              runRecursion(
                  leftNode == nullptr ? nullptr : leftNode->next,
                  rightNode == nullptr ? nullptr : rightNode->next,
                  ((leftNode == nullptr ? 0 : leftNode->val) +
                   (rightNode == nullptr ? 0 : rightNode->val) + carryVal) /
                      10));
        };

    // Runtime O(N)
    // Space O(N)
    return runRecursion(l1, l2, 0);
  }
};

#if 0  // Iterative Approach
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Initilization
    ListNode* Dummy = new ListNode();
    queue<uint8_t> Q;
    // Add Numbers
    int Carry = 0;
    while (l1 || l2) {
      int val1 = l1 ? l1->val : 0;
      int val2 = l2 ? l2->val : 0;
      int Digit = val1 + val2 + Carry;
      Carry = Digit / 10;
      Q.push(Digit % 10);
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    if (Carry) Q.push(Carry);
    // Yay!
    auto iTR = Dummy;
    while (!Q.empty())
      iTR->next = new ListNode(Q.front()), Q.pop(), iTR = iTR->next;
    return Dummy->next;
  }
};
#endif
