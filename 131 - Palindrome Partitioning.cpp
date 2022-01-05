#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool **__MEMORY;
  vector<vector<string>> __RESULT;

  void DynamicProgramming(const string &__String, int __Begin,
                          vector<string> *__CurrentList) {
    const auto __T_SIZE = static_cast<int>(__String.size());
    if (__Begin >= __T_SIZE) this->__RESULT.push_back(*__CurrentList);
    for (auto i = __Begin; i < __T_SIZE; ++i) {
      if (__String[__Begin] == __String[i] &&
          (i - __Begin <= 2 || this->__MEMORY[__Begin + 1][i - 1])) {
        this->__MEMORY[__Begin][i] = true;
        __CurrentList->push_back(__String.substr(__Begin, i - __Begin + 1));
        this->DynamicProgramming(__String, i + 1, __CurrentList);
        __CurrentList->pop_back();
      }
    }
  }

 public:
  vector<vector<string>> partition(const string &__String) {
    const auto __T_SIZE = __String.size();
    this->__MEMORY = new bool *[__T_SIZE];
    for (auto i = 0; i < __T_SIZE; ++i)
      this->__MEMORY[i] = new bool[__T_SIZE]();
    vector<string> CurrentList;
    this->DynamicProgramming(__String, 0, &CurrentList);
    return this->__RESULT;
  }
};

#if 0  // Works, But Slow
class Solution {
  string __String;
  int __String_SIZE;
  vector<vector<string>> __Result;

static bool isPalindrome(string_view __Str) {
  const int __SIZE = __Str.size();
  for (int i = 0; i < __SIZE / 2; ++i)
    if (__Str[i] != __Str[__SIZE - i - 1]) return false;
  return true;
}

  void Recursion(int __Begin, const vector<string>& __CurrentList) {
    const int __T_REMAIN_SIZE = __String_SIZE - __Begin;
    for (int i = 1; i <= __T_REMAIN_SIZE; ++i) {
      const string __T_Substr = __String.substr(__Begin, i);
      if (isPalindrome(__T_Substr)) {
        auto __T_NEW = __CurrentList;
        __T_NEW.push_back(__T_Substr);
        if (__Begin + i == __String_SIZE)
          __Result.push_back(__T_NEW);
        else
          this->Recursion(__Begin + i, __T_NEW);
      }
    }
  }

 public:
  vector<vector<string>> partition(const string& s) {
    this->__String = s;
    this->__String_SIZE = s.size();
    this->Recursion(0, {});
    return this->__Result;
  }
};
#endif
