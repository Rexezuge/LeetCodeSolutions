#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    auto Trip = new uint16_t[1000]();
    for (const auto& Vec : trips) {
      const auto& numPassengers = Vec[0];
      const auto& from = Vec[1];
      const auto& to = Vec[2];
      for (auto i = from; i < to; ++i) Trip[i] += numPassengers;
    }
    for (auto i = 0; i < 1000; ++i)
      if (Trip[i] > capacity) return false;
    return true;
  }
};
