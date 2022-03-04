---
title: 63. Unique Paths II
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/unique-paths-ii/)


## solution
```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n= obstacleGrid.size(), m= obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        //  0   0   0       1   1   1   
        //  0   1   0       1   0   1
        //  0   0   0       1   1   2
        for(int i=0;i<n;++i){
            for(int j =0;j<m;++j){
                if(obstacleGrid[i][j]==1) continue;
                // obstacleGrid[i][j] = 0
                if(i==0 && j==0) dp[0][0] = 1;
                else if(i==0) dp[i][j] = dp[i][j-1];
                else if(j==0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
       
        return dp.back().back();
        
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`

