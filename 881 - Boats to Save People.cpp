#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int numRescueBoats(vector<int>& people, const int limit) noexcept {
    // Sort Input
    sort(people.begin(), people.end());

    // Variable Initialization
    int leftIdx = 0, rightIdx = people.size() - 1;
    int numBoats = 1, currLimit = limit, currPeople = 2;

    // Perform Two Pointers
    while (leftIdx <= rightIdx) {
      if (currPeople > 0 && people[rightIdx] <= currLimit)
        currLimit -= people[rightIdx], --rightIdx, --currPeople;
      else if (currPeople > 0 && people[leftIdx] <= currLimit)
        currLimit -= people[leftIdx], ++leftIdx, --currPeople;
      else
        ++numBoats, currLimit = limit, currPeople = 2;
    }

    // Runtime O(NlogN)
    // Space O(1)
    return numBoats;
  }
};
