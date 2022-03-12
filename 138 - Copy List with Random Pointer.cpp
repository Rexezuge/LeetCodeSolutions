#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  static Node* copyRandomList(Node* head) noexcept {
    // Edge Case
    if (head == nullptr) return nullptr;

    // Variable Initialization
    Node* retVal;

    // Modify Original List
    // To Become the Following:
    // [7]-[Copy 7]-[13]-[Copy13]...
    {  // Begin Function
      Node* iTR = head;
      while (iTR != nullptr) {
        Node* newNode = new Node(iTR->val);
        Node* nextNode = iTR->next;
        iTR->next = newNode;
        newNode->next = nextNode;
        iTR = nextNode;
      }
    }  // End Function

    // Follow the Original List &
    // Update the Random Pointers
    {  // Begin Function
      Node* iTR = head;
      while (iTR != nullptr)
        iTR->next->random =
            iTR->random == nullptr ? nullptr : iTR->random->next,
        iTR = iTR->next->next;
    }  // End Function

    // Disconnect Copied List
    // From Original List
    {  // Begin Function
      Node dummyNode(0);
      Node* copyList = &dummyNode;
      Node* iTR = head;
      while (iTR != nullptr) {
        copyList->next = iTR->next;
        copyList = copyList->next;
        iTR->next = iTR->next->next;
        iTR = iTR->next;
      }
      retVal = dummyNode.next;
    }  // End Function

    // Runtime O(N)
    // Space O(1)
    return retVal;
  }
};
