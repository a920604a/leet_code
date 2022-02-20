---
title: 198. House Robber
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/house-robber/)


## solution 
維護一個dp，`max(dp[i-1], dp[i-2]+nums[i])`


```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        
        //  1   2   3   1
        //  1   2   4   4 
        
        int n = nums.size();
        vector<int> dp(n,0);
        if(n==1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<n;++i){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp.back();
    }
};
```

- reduce dp
```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        //  1   2   3   1
        //  1   2   4   4

        int n = nums.size();
        vector<int> dp(n,0);
        if(n==1) return nums[0];
        int dp0 = nums[0], dp1 = max(nums[0], nums[1]);
        int ret = dp1;
        for(int i=2;i<n;++i){
            ret = max(dp0 + nums[i], dp1);
            dp0 = dp1;
            dp1 = ret;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)` -> `O(1)`
