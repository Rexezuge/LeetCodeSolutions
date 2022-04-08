#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class KthLargest {
  const int m_MaxKthElements;
  unique_ptr<priority_queue<int, vector<int>, function<bool(int, int)>>>
      m_ElementsQueue;

 public:
  explicit KthLargest(const int k, const vector<int>& nums) noexcept;

  int add(const int val) noexcept;
};

KthLargest::KthLargest(const int k, const vector<int>& nums) noexcept
    : m_MaxKthElements(k),
      m_ElementsQueue(
          new priority_queue<int, vector<int>, function<bool(int, int)>>(
              [](const int left, const int right) { return left > right; })) {
  for (size_t i = 0; i < nums.size(); ++i) m_ElementsQueue->push(nums[i]);
  while (m_ElementsQueue->size() > m_MaxKthElements) m_ElementsQueue->pop();
}

int KthLargest::add(const int val) noexcept {
  m_ElementsQueue->push(val);
  if (m_ElementsQueue->size() > m_MaxKthElements) m_ElementsQueue->pop();
  return m_ElementsQueue->top();
}
