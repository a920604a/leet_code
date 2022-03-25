---
title: 368. Largest Divisible Subset
tags:
    - Math
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/largest-divisible-subset/)
## solution
```c++
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n,0), parent(n,0), ret ;
        int mx = 0, mx_idx = 0;
        for(int i=n-1 ; i>-1;i--){
            for(int j=i ; j<n;j++){
                if(nums[j]%nums[i] == 0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                    if(mx<dp[i]){
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        }
        for(int i=0;i<mx ; ++i){
            ret.push_back(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        return ret;
                                    
        
        
    }
};
```
## analysis
- time complexity `O(n^2)`
- space complexity `O(n)`