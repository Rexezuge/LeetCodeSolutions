#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int lastStoneWeight(vector<int>& stones) noexcept {
    // Create a Max Heap
    make_heap(stones.begin(), stones.end());

    // Run Simulation
    while (stones.size() >= 2) {
      int stone1 = stones.front();
      pop_heap(stones.begin(), stones.end());
      stones.pop_back();
      int stone2 = stones.front();
      pop_heap(stones.begin(), stones.end());
      stones.pop_back();
      if (stone1 == stone2) continue;
      stones.push_back(stone1 - stone2);
      push_heap(stones.begin(), stones.end());
    }

    // Runtime O(NlogN)
    // Space O(1)
    return stones.empty() ? 0 : stones.front();
  }
};
