#include <bits/stdc++.h>
using namespace std;

class Solution {
  int Key;

  int findPivot(const vector<int>& nums) const noexcept {
    int n = nums.size();
    int s = 0, e = nums.size() - 1, mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e) {
      int prev = (mid - 1 + n) % n, next = (n + 1) % n;
      if (nums[mid] <= nums[next] and nums[mid] <= nums[prev])
        return mid;
      else if (nums[mid] <= nums[e]) {
        ans = mid;
        e = mid;
      } else {
        s = mid + 1;
      }
      mid = s + (e - s) / 2;
    }
    return ans;
  }

  int binarySearch(const vector<int>& nums, int begin, int end) const noexcept {
    // Base Case
    if (begin == end) return nums[begin] == Key ? begin : -1;
    if (begin + 1 == end) {
      if (nums[begin] == Key)
        return begin;
      else if (nums[end] == Key)
        return end;
      return -1;
    }
    // Recursion
    const int mid_idx = begin + (end - begin) / 2;
    const int mid_val = nums[mid_idx];
    if (mid_val == Key) return mid_idx;
    if (mid_val < Key) return binarySearch(nums, mid_idx, end);
    return binarySearch(nums, begin, mid_idx);
  }

 public:
  int search(const vector<int>& nums, int target) noexcept {
    // Edge Case
    if (nums.size() == 1) return nums[0] == target ? 0 : -1;
    // Initialization
    Key = target;
    const int Pivot =
        nums.front() > nums.back() || nums.size() == 1 ? findPivot(nums) : 0;
    if (nums[Pivot] == Key) return Pivot;
    cout << "Pivot: " << Pivot << ", Val: " << nums[Pivot] << endl;
    // Yay!
    if (Pivot == 0) return binarySearch(nums, 0, nums.size() - 1);
    return target > nums[nums.size() - 1]
               ? binarySearch(nums, 0, Pivot - 1)
               : binarySearch(nums, Pivot, nums.size() - 1);
  }
};
