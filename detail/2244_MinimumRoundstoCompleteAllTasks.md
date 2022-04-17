---
title: 2244. Minimum Rounds to Complete All Tasks
tags:
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/)

## solution
```c++
class Solution {
public:
    int minStep(int n){
        //  0   1   2   3   4   5   6   7   8
        //  1   1   1   1   2   2   2   3   3
        
        //  0   1   2   3   4
        if(n<2) return -1;
        if(n==2 || n==3) return 1;
        vector<int> dp(n+1,1);
        for(int i=4;i<=n;++i){
            dp[i] = min(dp[i-2]+1, dp[i-3]+1);
        }
        return dp[n];
        
    }
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> mp;
        for(int t:tasks) mp[t]++;
        int step = 0;
        for(auto &m:mp){
            int count = minStep(m.second);
            if(count==-1) return -1;
            step+=count;
        }
        return step;
    }
};
```
#### option 2
```c++
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> mp;
        for(int t:tasks) mp[t]++;
        int step = 0;
        for(auto &m:mp){
            if(m.second==1) return -1;
            double x = (double)m.second/3.0;
            step+=ceil(x);
        }
        return step;
    }
};
```
## analysis
- time complexity `O(nlogn)` `O(logn)`
- space complexity `O(n)` 