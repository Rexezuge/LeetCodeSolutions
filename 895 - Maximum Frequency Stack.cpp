#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class FreqStack {
  int maxFreq;
  unordered_map<int, int> freqMap;
  unordered_map<int, stack<int>> setMap;

 public:
  FreqStack() : maxFreq(0), freqMap(), setMap() {}

  void push(int val) noexcept {
    int valFreq = freqMap[val] + 1;
    freqMap[val] = valFreq;
    maxFreq = max(maxFreq, valFreq);
    setMap[valFreq].push(val);
  }

  int pop() noexcept {
    int topFreq = setMap[maxFreq].top();
    setMap[maxFreq].pop();
    --freqMap[topFreq];
    if (setMap[maxFreq].empty()) --maxFreq;
    return topFreq;
  }
};
