---
title: 45. Jump Game II
tags:  
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)

## solution

#### option 1 - dp
```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        //  2   3   1   1   4
        //      1   1   
        //      1   1   2   2
        //      1   1   2
        
        int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<=i+nums[i] && j<n; ++j){
                dp[j] = min(dp[i]+1,  dp[j]);
            }
        }
        
        return dp[n-1];
    }
};
```


#### option 2 - gredy
```c++

```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`