class Solution {
 public:
  int rob(const vector<int>& nums) {
    if (nums.size() == 1) {
      return nums.front();
    } else if (nums.size() == 2) {
      return max(nums.front(), nums[1]);
    } else if (nums.size() == 3) {
      return max(nums.front(), max(nums.front() + nums.back(), nums[1]));
    }
    vector<int> Result(nums);
    Result[2] += Result.front();
    for (uint8_t i = 3; i < (uint8_t)Result.size(); ++i) {
      uint16_t OneThree = nums[i - 3] + nums[i - 1];
      uint16_t TwoFour = nums[i - 2] + nums[i];
      uint16_t OneFour = nums[i - 3] + nums[i];
      uint16_t Halt = Result[i - 2] + nums[i];
      if (i == 4) {
        TwoFour += Result[i - 3 - 1];
      }
      if (i >= 5) {
        OneThree += Result[i - 3 - 2];
        TwoFour += Result[i - 3 - 1];
        OneFour += Result[i - 3 - 2];
      }
      Result[i] =
          max(OneThree,
              max(TwoFour, max(OneFour, max(Halt, (uint16_t)Result[i - 1]))));
    }
    return Result.back();
  }
};
