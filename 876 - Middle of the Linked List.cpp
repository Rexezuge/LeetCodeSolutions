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
  ListNode* middleNode(ListNode* const HEAD) {
    ListNode *_H = HEAD, *_iTR = HEAD;
    while (_iTR && _iTR->next) {
      _H = _H->next;
      _iTR = _iTR->next->next;
    }
    return _H;
  }
};
