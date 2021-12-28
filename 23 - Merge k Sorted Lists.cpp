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
  ListNode* mergeKLists(const vector<ListNode*>& lists) {
    if (lists.size() == 0) {
      return nullptr;
    } else if (lists.size() == 1) {
      return lists[0];
    }
    ListNode* L =
        this->mergeKLists({lists.begin(), lists.begin() + lists.size() / 2});
    ListNode* R =
        this->mergeKLists({lists.begin() + lists.size() / 2, lists.end()});
    ListNode* RES = new ListNode;
    ListNode* iTR = RES;
    while (L || R) {
      if (!L) {
        iTR->next = R;
        break;
      } else if (!R) {
        iTR->next = L;
        break;
      }
      if (L->val < R->val) {
        iTR->next = L;
        L = L->next;
        iTR = iTR->next;
      } else {
        iTR->next = R;
        R = R->next;
        iTR = iTR->next;
      }
    }
    return RES->next;
  }
};

#if 0  // Trade CPU for Memory
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* RES = new ListNode;
    ListNode* iTR = RES;
    int P = lists.size();
    while (P) {
      int I = -1, S = INT_MAX;
      for (int i = 0; i < lists.size(); ++i) {
        if (lists[i] && lists[i]->val < S) {
          I = i;
          S = lists[i]->val;
        }
      }
      if (I < 0) {
        --P;
        continue;
      }
      iTR->next = lists[I];
      iTR = iTR->next;
      lists[I] = lists[I]->next;
      if (!lists[I]) {
        --P;
      }
    }
    return RES->next;
  }
};
#endif
