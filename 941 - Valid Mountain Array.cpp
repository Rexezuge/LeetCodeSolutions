#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool validMountainArray(vector<int>& arr) {
    const int16_t n = arr.size();
    int16_t i = 0, j = n - 1;

    // mountain array if and only if: arr.length >= 3
    // should start with decreasing order
    if (n < 3 || arr[0] > arr[1]) return false;

    // found first decreasing number from begin
    while (i < n - 1 && arr[i] < arr[i + 1]) ++i;

    // found first decreasing number from end
    while (j > 0 && arr[j] < arr[j - 1]) --j;

    // it should be same
    return i > 0 && i == j && j < n - 1;
  }
};
