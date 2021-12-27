#include <bits/stdc++.h>
#define ASCII_SHIFT 48
using namespace std;

class Solution {
 private:
  const vector<string> BOOK{"",    "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};

 public:
  vector<string> letterCombinations(string& digits) {
    if (digits.empty()) {
      return {};
    }
    reverse(digits.begin(), digits.end());
    return this->Recur(digits);
  }
  vector<string> Recur(const string& digits) {
    // Base Case
    if (digits.size() == 1) {
      const string& REF = BOOK[digits.back() - ASCII_SHIFT];
      vector<string> R;
      for (const auto& i : REF) {
        R.push_back(string(1, i));
      }
      return R;
    }
    // Recursion
    const string& REF = BOOK[digits.back() - ASCII_SHIFT];
    const string& NEXT = digits.substr(0, digits.size() - 1);
    vector<string> RESULT;
    for (const auto& i : REF) {
      auto R = this->Recur(NEXT);
      for (const auto& C : R) {
        RESULT.push_back(string(1, i) + C);
      }
    }
    return RESULT;
  }
};
