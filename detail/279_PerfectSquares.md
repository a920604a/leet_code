---
title: 279. Perfect Squares
tags:  
    - dp
    - math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/perfect-squares/)

## solution

#### option 1 - dp
```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        //  0   1   2   3   4   5   6   7   8   9   10  11  12
        //  0   1   2   3   1   2   3   4   2   1   2   3   3
        for(int i=0;i<=n;++i){
            for(int j = 1;i+j*j<=n;++j){
                dp[i+j*j] = min(dp[i]+1, dp[i+j*j]);
            }
        }
        return dp[n];
        
    }
};
```
#### option 2 - math
## analysis
- time complexity `O(n*sqrt(n))` `O(sqrt(n))`
- space complexity `O(1)`