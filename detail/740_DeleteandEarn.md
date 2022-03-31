---
title: 740. Delete and Earn
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/delete-and-earn/)

## solution
這就是變形的強盜問題`198. House Robber`
```c++
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //  
        vector<int> dp(10001,0);
        for(int n:nums) dp[n]++;
        for(int i=1;i<=10000;++i) dp[i] = i*dp[i];
        int ret = 0;
        ret = max(dp[0], dp[1]);
        for(int i=2;i<=10000;++i){
            dp[i] = max(dp[i-2]+dp[i], dp[i-1]);
            ret = max(ret, dp[i]);
        }
        return ret;
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
