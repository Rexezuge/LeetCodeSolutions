class Solution {
 public:
  static int brokenCalc(int startValue, int target) noexcept {
    // Variable Initialization
    int retVal = 0;

    // Perform the Algorithm
    while (target > startValue) {
      ++retVal;
      target % 2 == 1 ? ++target : target /= 2;
    }

    // Runtime O(logN)
    // Space O(1)
    return retVal + startValue - target;
  }
};
