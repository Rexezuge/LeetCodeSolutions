#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int strStr(string& __haystack, const string& __needle) {
    if (__needle.empty()) return {0};
    if (__haystack.size() < __needle.size()) return {-1};
    for (int i = 0; i < __haystack.size() - __needle.size() + 1; ++i) {
      if (__haystack.substr(i, __needle.size()) == __needle) {
        return {i};
      }
    }
    return {-1};
  }
};
