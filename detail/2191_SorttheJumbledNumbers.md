---
title: 2191. Sort the Jumbled Numbers
tags:
    - hash table
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/sort-the-jumbled-numbers/)


## solution
```c++
class Solution {
public:
    unordered_map<int,int> mp;
    int decode(int val ){
        if(val==0) return mp[0];
        int n = 0, m= val;
        while(m){
            n++;
            m/=10;
        }
        int ret = 0, i=0;
        while(i<n){
            ret += mp[val%10]*pow(10,i++);
            val /=10;
        }
        return ret;
        
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n = mapping.size();
        for(int i =0;i<n;++i) mp[i] = mapping[i];
        vector<pair<int,int>> ret;
        for(int n:nums){
            ret.push_back(make_pair(n, decode(n)));
            // cout<<ret.back().first<<" "<<ret.back().second<<endl;
        }
        sort(ret.begin(), ret.end(), [](pair<int,int>&a , pair<int,int> b){
            return a.second<b.second;
        });
        vector<int> ans;
        for(auto r:ret){
            ans.push_back(r.first);
            // cout<<r.first<<" "<<r.second<<endl;
        }
        return ans;
        
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`