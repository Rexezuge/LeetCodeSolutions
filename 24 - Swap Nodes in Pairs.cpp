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
  ListNode* swapPairs(ListNode* __HEAD) {
    ListNode* RES = new ListNode(0, __HEAD);
    ListNode* iTR = RES;
    while (iTR && iTR->next && iTR->next->next) {
      ListNode* N1 = iTR->next;
      ListNode* N2 = iTR->next->next;
      ListNode* N3 = iTR->next->next->next;
      iTR->next = N2;
      N2->next = N1;
      N1->next = N3;
      iTR = iTR->next->next;
    }
    return RES->next;
  }
};
