---
title: 746. Min Cost Climbing Stairs
tags:
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/min-cost-climbing-stairs/)

## solution

當前位置的花費，是前兩個位置累積的花費加上前兩個位置的花費`min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);`

```c++
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        //  10  15  20
        //          15  
        
        
        //  1   100 1   1   1   1   100 1   1   100 1
        //          1   
        int n = cost.size();
        vector<int> dp(n+1,0);
        for(int i=2;i<n+1;++i){
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp.back();
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`