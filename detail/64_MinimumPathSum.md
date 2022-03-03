---
title: 64. Minimum Path Sum

tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/minimum-path-sum/)

## solution

```c++

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        //  1   3   1       1   4   5
        //  1   5   1       2   7   6
        //  4   2   1       6   8   7
        
        int n = grid.size(), m=grid[0].size();
        
        vector<vector<int>> dp = grid;
        int path = 0;
        for(int j=1;j<m;++j) dp[0][j] +=dp[0][j-1];
        if(n==1) return dp.back().back();
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                if(j==0) dp[i][j] += dp[i-1][j];
                else dp[i][j] += min(dp[i-1][j], dp[i][j-1]) ;
            }
        }
        return dp.back().back();
    }
};
```


## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`