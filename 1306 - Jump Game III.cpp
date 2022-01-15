#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool BFS(vector<int>&arr,int start){
        const auto CurrVal=arr[start];
        if(CurrVal==0) return true;
        arr[start]=(-1)*CurrVal;
        if(start-CurrVal>=0 && arr[start-CurrVal]>=0)
            if(BFS(arr,start-CurrVal)) return true;
        if(start+CurrVal<arr.size() && arr[start+CurrVal]>=0)
            if(BFS(arr,start+CurrVal)) return true;
        // arr[start]=(-1)*CurrVal; No Need Because of Duplicate Node is a Cycle
        return false;
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        return BFS(arr,start);
    }
};
