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
  ListNode* removeNthFromEnd(ListNode* const HEAD, const int& N) {
    // Get the Size of the List
    int _SIZE = 0;
    for (ListNode* _iTR = HEAD; _iTR; _iTR = _iTR->next) {
      ++_SIZE;
    }
    // Get the Index to be Removed
    const int _INDEX = _SIZE - N;
    // Remove from List
    if (_INDEX != 0) {
      // Not Removing HEAD
      ListNode* _iTR = HEAD;
      ListNode* _PREV = nullptr;
      int _i = 0;
      while (_i != _INDEX) {
        if (_i + 1 == _INDEX) {
          _PREV = _iTR;
        }
        ++_i;
        _iTR = _iTR->next;
      }
      _PREV->next = _iTR->next;
      return HEAD;
    } else {
      // Removing HEAD
      return HEAD->next;
    }
  }
};
