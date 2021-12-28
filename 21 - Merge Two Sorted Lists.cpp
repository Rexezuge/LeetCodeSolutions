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
  ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
    ListNode* const _R = new ListNode;
    ListNode* _iTR = _R;
    while (L1 || L2) {
      if (!L1) {
        _iTR->next = L2;
        break;
      } else if (!L2) {
        _iTR->next = L1;
        break;
      }
      if (L1->val < L2->val) {
        _iTR->next = L1;
        L1 = L1->next;
        _iTR = _iTR->next;
      } else {
        _iTR->next = L2;
        L2 = L2->next;
        _iTR = _iTR->next;
      }
    }
    return _R->next;
  }
};
