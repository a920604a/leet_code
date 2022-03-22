---
title: 377. Combination Sum IV
tags:
    - backtracking
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/combination-sum-iv/)

## solution 
- dfs , TLE
```c++
class Solution {
public:
    int ret = 0;
    void dfs(vector<int> & nums, int target, vector<int> & path, int s){
        if(target<0) return;
        if(target==0) {
            ret++;
            return;
        }
        for(int i=0;i<nums.size();++i){
            path.push_back(nums[i]);
            dfs(nums, target-nums[i], path, i);
            path.pop_back();
        }
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> path;
        dfs(nums, target, path,0);
        return ret;
        
    }
};
```
#### option 1 - dp
```c++
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        int n= nums.size();
        vector<unsigned long long> dp(target+1,0);
        dp[0] = 1;
        for(int i=1;i<=target;++i){
            for(auto a:nums){
                if(i>=a ) dp[i] += dp[i-a];
            }
        }
        return dp.back();   
    }
};
```