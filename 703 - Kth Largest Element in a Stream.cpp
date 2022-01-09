#include <bits/stdc++.h>
using namespace std;

class KthLargest {
  int K;
  priority_queue<int, vector<int>, greater<int>> Q;

 public:
  KthLargest(int k, vector<int>& nums) {
    K = k;
    for (auto& i : nums) Q.push(move(i));
    while (Q.size() > K) Q.pop();
  }

  int add(int val) {
    Q.push(val);
    if (Q.size() > K) Q.pop();
    return Q.top();
  }
};

#if 0  // Works, Using multiset
class KthLargest {
  int k;
  multiset<int> nums;

 public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    sort(nums.rbegin(), nums.rend());
    for (int i = 0; i < min(k, static_cast<int>(nums.size())); ++i)
      this->nums.insert(nums[i]);
  }

  int add(int val) {
    nums.insert(val);
    if (nums.size() > k) nums.erase(nums.begin());
    return *nums.begin();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
#endif
