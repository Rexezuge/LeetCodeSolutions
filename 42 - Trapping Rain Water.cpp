#include <bits/stdc++.h>
using namespace std;

namespace std {
uint16_t max(uint16_t A, uint16_t B) { return A > B ? A : B; }
}  // namespace std

class Solution {
 public:
  int trap(vector<int>& height) {
    // Initilization
    const auto& __SIZE = height.size();
    int Result = 0;
    uint16_t** Memory = new uint16_t*[__SIZE];
    for (int i = 0; i < __SIZE; ++i) Memory[i] = new uint16_t[2];
    // Dynamic Programming
    Memory[0][0] = height[0];
    Memory[__SIZE - 1][1] = height[__SIZE - 1];
    for (int i = 1; i < __SIZE; ++i)
      Memory[i][0] = max(height[i], Memory[i - 1][0]);
    for (int i = __SIZE - 2; i >= 0; --i)
      Memory[i][1] = max(height[i], Memory[i + 1][1]);
    for (int i = 0; i < __SIZE; ++i)
      Result += min(Memory[i][0], Memory[i][1]) - height[i];
    // Yay!
    for (int i = 0; i < __SIZE; ++i) delete[] Memory[i];
    delete[] Memory;
    return Result;
  }
};

#if 0  // Time Limit Exceeded
class Solution {
 public:
  int trap(vector<int>& height) {
    const auto & __SIZE=height.size();
    int Result = 0;
    for (int i = 0; i < __SIZE; ++i) {
      int Left = 0, Right = 0;
      for (int iL = 0; iL <= i; ++iL) Left = max(Left, height[iL]);
      for (int iR = i; iR < __SIZE; ++iR) Right = max(Right, height[iR]);
      Result += min(Left, Right) - height[i];
    }
    return Result;
  }
};
#endif
