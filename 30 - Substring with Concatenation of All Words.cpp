#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string& __s, const vector<string>& __words) {
    vector<int> Result;
    unordered_map<string, int> WordMap;
    for (const auto& i : __words) ++WordMap[i];
    for (int i = 0, __T_WORD_LENGTH = __words[0].size(),
             __T_WORD_SIZE = __words.size(),
             __T_LOOP_SIZE = __s.size() - __T_WORD_LENGTH + 1;
         i < __T_LOOP_SIZE; ++i) {
      if (WordMap.find(__s.substr(i, __T_WORD_LENGTH)) == WordMap.end())
        continue;
      unordered_map<string, int> WordMap_FIND;
      for (int iP = i;
           iP < __T_LOOP_SIZE && iP < i + __T_WORD_LENGTH * __T_WORD_SIZE;
           iP += __T_WORD_LENGTH)
        ++WordMap_FIND[__s.substr(iP, __T_WORD_LENGTH)];
      if (WordMap_FIND == WordMap) Result.push_back(i);
    }
    return Result;
  }
};

#if 0  // Does Not Work On One Edge Case
class Solution {
 public:
  vector<int> findSubstring(string& __s, const vector<string>& __words) {
    string Target;
    vector<int> Result;
    for (const auto& i : __words) Target.append(i);
    sort(Target.begin(), Target.end());
    for (int i = 0, __T_LOOP_SIZE = __s.size() - Target.size() + 1,
             __T_INCRE_SIZE = __words[0].size(),
             __T_SUBSTR_SIZE = Target.size();
         i < __T_LOOP_SIZE;) {
      string ss = __s.substr(i, __T_SUBSTR_SIZE);
      const string __T_OUT=ss;
      const int __T_INDEX=i;
      sort(ss.begin(), ss.end());
      if (ss == Target) {
        Result.push_back(i);
        i += __T_INCRE_SIZE;
      } else {
        ++i;
      }
    }
    return Result;
  }
};
#endif
