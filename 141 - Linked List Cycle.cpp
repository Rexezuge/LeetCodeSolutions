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
  bool hasCycle(ListNode *head) {
    auto Slow = head, Fast = head;
    while (Fast && Fast->next) {
      Slow = Slow->next;
      Fast = Fast->next->next;
      if (Slow == Fast) return true;
    }
    return false;
  }
};
