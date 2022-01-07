#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *Head;

 public:
  Solution(ListNode *head) { this->Head = head; }

  int getRandom() {
    int Index = 1, ChosenValue = 0;
    auto iTR = this->Head;
    while (iTR) {
      if (rand() % Index == 0) ChosenValue = iTR->val;
      ++Index;
      iTR = iTR->next;
    }
    return ChosenValue;
  }
};
