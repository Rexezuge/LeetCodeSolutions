#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    // Base Case
    if (num.size() == k) return "0";
    // Initilization
    stack<char> S;
    const int size = num.size(), desired = size - k;
    // Remove K Digits
    for (int i = 0; i < size; ++i) {
      while (!S.empty() && S.size() + size - i > desired && S.top() > num[i])
        S.pop();
      S.push(num[i]);
    }
    while (S.size() > desired) S.pop();
    // Yay!
    string Result;
    while (!S.empty()) Result.push_back(S.top()), S.pop();
    reverse(Result.begin(), Result.end());
    int Z = 0;
    while (Result[Z] == '0') ++Z;
    return Z != Result.size() ? Result.substr(Z) : "0";
  }
};
