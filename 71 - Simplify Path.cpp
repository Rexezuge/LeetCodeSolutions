#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static string simplifyPath(string_view path) noexcept {
    // Variable Initialization
    stack<string> stringStack;
    string retVal;

    // Add Path to Stack
    for (int i = 0, __END = path.size(); i < __END; ++i) {
      if (path[i] == '/') continue;
      string tmpString;
      while (i < __END && path[i] != '/') tmpString.push_back(path[i++]);
      if (tmpString == ".") {
        continue;
      } else if (tmpString == "..") {
        if (!stringStack.empty()) stringStack.pop();
      } else {
        stringStack.push(tmpString);
      }
    }

    // Edge Case
    if (stringStack.empty()) return "/";

    // Construct Canonical Path
    while (!stringStack.empty())
      retVal = "/" + move(stringStack.top()) + retVal, stringStack.pop();

    // Runtime O(N)
    // Space O(N)
    return retVal;
  }
};
