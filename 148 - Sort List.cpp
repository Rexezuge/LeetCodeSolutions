#pragma GCC opptimize("fast")
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
  static ListNode* sortList(ListNode* param_head) noexcept {
    function<ListNode*(ListNode*)> getMid = [&](ListNode* head) {
      ListNode* fast = head;
      while (fast && fast->next) head = head->next, fast = fast->next->next;
      return head;
    };

    function<bool(ListNode*)> hasTwo = [&](ListNode* head) {
      if (head != nullptr && head->next != nullptr &&
          head->next->next == nullptr)
        return true;
      return false;
    };

    function<ListNode*(ListNode*)> mergeSort = [&](ListNode* head) {
      // Zero / One Element in List
      if (head == nullptr || head->next == nullptr) return head;

      ListNode *dummy_head = new ListNode(), *__ADDRESS = dummy_head;

      ListNode* mid = getMid(head);
      if (mid == head->next) {
        if (hasTwo(head)) {
          // Two Elements in List
          if (head->val < mid->val) {
            dummy_head->next = head;
            dummy_head->next->next = mid;
          } else {
            head->next = nullptr;
            dummy_head->next = mid;
            dummy_head->next->next = head;
          }
          dummy_head->next->next->next = nullptr;
          return __ADDRESS->next;
        } else {
          // Three Elements in List
          vector<ListNode*> Vec;
          Vec.push_back(head);
          Vec.push_back(head->next);
          Vec.push_back(head->next->next);
          sort(Vec.begin(), Vec.end(),
               [](const auto& A, const auto& B) { return A->val > B->val; });
          while (Vec.empty() == false) {
            dummy_head->next = Vec.back();
            Vec.pop_back();
            dummy_head = dummy_head->next;
          }
          dummy_head->next = nullptr;
          return __ADDRESS->next;
        }
      }

      ListNode *part_one = head, *part_two = mid->next;
      mid->next = nullptr;
      part_one = mergeSort(part_one);
      part_two = mergeSort(part_two);

      while (part_one != nullptr || part_two != nullptr) {
        if (part_one == nullptr) {
          dummy_head->next = part_two;
          break;
        }
        if (part_two == nullptr) {
          dummy_head->next = part_one;
          break;
        }
        if (part_one->val < part_two->val) {
          dummy_head->next = part_one;
          part_one = part_one->next;
        } else {
          dummy_head->next = part_two;
          part_two = part_two->next;
        }
        dummy_head = dummy_head->next;
      }

      return __ADDRESS->next;
    };

    return mergeSort(param_head);
  }
};
