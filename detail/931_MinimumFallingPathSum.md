---
title: 931. Minimum Falling Path Sum
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/minimum-falling-path-sum/)


## solution

#### option 1 - dp
```c++
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp = matrix;
        int ret = INT_MAX;
        for(int n:matrix[0]) ret = min(ret, n);
        if(n==1) return ret;
        ret = INT_MAX;
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                if(j==0) dp[i][j] += min(dp[i-1][j], dp[i-1][j+1]);
                else if(j==m-1) dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]);
                else dp[i][j] += min(min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]);
                if(i==n-1) ret = min(ret, dp[i][j]);
            }
        }
        return ret;
        
    }
};
```


## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`