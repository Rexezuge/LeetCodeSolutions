#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<int> topKFrequent(const vector<int>& nums, int k) noexcept {
    // Construct A Frequency Map
    unordered_map<int, int> numFrequency;
    for (int i : nums) ++numFrequency[i];

    // Construct A Heap
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   function<bool(pair<int, int>, pair<int, int>)>>
        maxHeap([](const pair<int, int>& a, const pair<int, int>& b) {
          return a.second < b.second;
        });
    for (const auto& [k, v] : numFrequency) maxHeap.push({k, v});

    // Construct The Result Vector
    vector<int> retVal;
    while (k-- > 0) retVal.push_back(maxHeap.top().first), maxHeap.pop();

    // Runtime O(NlogN)
    // Space O(N)
    return retVal;
  }
};
