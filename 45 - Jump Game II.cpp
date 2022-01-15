#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    int Furthest=0,Steps=0,Begin=0,End=0;
    const int TermCondi=nums.size()-1;
    while(Furthest<TermCondi) {
      for(int i=Begin;i<=End;++i)
        Furthest=max(Furthest,i+nums[i]);
      ++Steps;
      Begin=End+1;
      End=Furthest;
    }
    return Steps;
  }
};
