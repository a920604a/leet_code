---
title: 64. Minimum Path Sum

tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/minimum-path-sum/)

## solution
#### option 1 - dp
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size(),  m =grid[0].size();
        vector<vector<int>> dp = grid;
        //  1   3   1       1   4   4
        //  1   5   1
        //  4   2   1
        for(int i=0;i<n;++i){
            for(int j = 0;j< m ; ++j){
                if(i==0 && j==0) continue;
                else if(i==0) dp[i][j]+=dp[i][j-1];
                else if(j==0) dp[i][j]+=dp[i-1][j];
                else dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
```

#### option 2 - reduce dp
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size(),  m =grid[0].size();
        vector<int> dp(m,0);
        dp[0] = grid[0][0];
        //  1   3   1       1   4   4
        //  1   5   1       
        //  4   2   1
        for(int i=0;i<n;++i){
            for(int j = 0;j< m ; ++j){
                if(i==0 && j==0) dp[j] = grid[i][j];
                else if(i==0) dp[j] = grid[i][j] + dp[j-1];
                else if(j==0) dp[j] += grid[i][j];
                else dp[j] = min(dp[j], dp[j-1])+ grid[i][j];
            }
        }
        return dp[m-1];
    }
};
```
#### option 3 - dp
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size(),  m =grid[0].size();
        //  1   3   1       1   4   4
        //  1   5   1       
        //  4   2   1
        for(int i=0;i<n;++i){
            for(int j = 0;j< m ; ++j){
                if(i==0 && j==0) continue;
                else if(i==0) grid[i][j] += grid[i][j-1];
                else if(j==0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(nm)` `O(n)` `O(1)`