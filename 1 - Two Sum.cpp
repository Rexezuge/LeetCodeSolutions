#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> HASHMAP;
        for(size_t i=0;i!=nums.size();++i){
            const int DIFF=target-nums[i];
            auto MATCH_PAIR=HASHMAP.find(DIFF);
            if(MATCH_PAIR!=HASHMAP.end()){
                return vector<int>{static_cast<int>(i),MATCH_PAIR->second};
            }
            HASHMAP.insert(pair<int,int>(nums[i],static_cast<int>(i)));
        }
        return vector<int>{};
    }
};
