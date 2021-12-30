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
  ListNode* reverseKGroup(ListNode* __HEAD, int __K) {
    auto R = new ListNode(0, __HEAD);
    auto iTR = R;
    vector<ListNode*> Q;
    Q.reserve(__K);
    while (true) {
      auto _T = iTR->next;
      for (int i = 0; i < __K && _T; ++i) {
        Q.push_back(_T);
        _T = _T->next;
      }
      if (Q.size() == __K) {
        auto _N = Q.back()->next;
        for (int i = Q.size() - 1; i >= 0; --i) {
          iTR->next = Q[i];
          iTR = iTR->next;
        }
        iTR->next = _N;
        Q.clear();
      } else {
        break;
      }
    }
    return R->next;
  }
};
