#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int>* __nums;
  int** __memory;

  int DynamicProgramming(const int& __left, const int& __right) noexcept {
    if (__left == __right) {
      return {0};
    }
    int MaxResult = 0;
    for (int i = __left; i < __right; ++i) {
      int LeftSide, RightSide;
      if (__memory[__left][i] == 0) {
        LeftSide = this->DynamicProgramming(__left, i);
        __memory[__left][i] = LeftSide;
      } else {
        LeftSide = __memory[__left][i];
      }
      if (__memory[i + 1][__right] == 0) {
        RightSide = this->DynamicProgramming(i + 1, __right);
        __memory[i + 1][__right] = RightSide;
      } else {
        RightSide = __memory[i + 1][__right];
      }
      MaxResult = max(MaxResult, LeftSide + RightSide +
                                     __nums->operator[](__left - 1) *
                                         __nums->operator[](i) *
                                         __nums->operator[](__right));
    }
    return MaxResult;
  }

 public:
  int maxCoins(vector<int>& __balloons) noexcept {
    __nums = &__balloons;
    __nums->insert(__nums->begin(), {1});
    __nums->push_back({1});
    __memory = new int*[__nums->size()]();
    for (int i = 0; i < __nums->size(); ++i) {
      __memory[i] = new int[__nums->size()]();
    }
    return this->DynamicProgramming(1, __nums->size() - 1);
  }
};

#if 0  // Does Not Work: Greedy Algorithm
class Solution {
  struct Node {
    int index;
    int val;
    int left;
    int right;
  };

 public:
  int maxCoins(vector<int>& __nums) {
    int Result = 0;
    while (!__nums.empty()) {
      if (__nums.size() == 1) {
        Result += __nums.front();
        __nums.clear();
        break;
      } else if (__nums.size() == 2) {
        Node LeftMost{0, __nums.front(), 1, __nums.back()};
        Node RightMost{1, __nums.back(), __nums.front(), 1};
        if (LeftMost.val < RightMost.val) {
          Result += LeftMost.val * LeftMost.left * LeftMost.right;
          __nums.erase(__nums.begin());
          cout << "Left" << endl;
        } else {
          Result += RightMost.val * RightMost.left * RightMost.right;
          __nums.erase(__nums.begin() + 1);
          cout << "Right" << endl;
        }
        continue;
      }
      Node Current{1, __nums[1], __nums[0], __nums.size() >= 3 ? __nums[2] : 1};
      for (int i = 2; i < __nums.size() - 1; ++i) {
        if (__nums[i] < Current.val) {
          if (Current.left + Current.right < __nums[i - 1] + __nums[i + 1]) {
            Current = {i, __nums[i], __nums[i - 1], __nums[i + 1]};
          }
        }
      }
      cout << "Index: " << Current.index << " Val: " << Current.val
           << " Left: " << Current.left << " Right: " << Current.right << endl;
      Result += Current.val * Current.left * Current.right;
      __nums.erase(__nums.begin() + Current.index);
    }
    return Result;
  }
};
#endif
