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
