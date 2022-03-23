---
title: 174. Dungeon Game
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/dungeon-game/)

## solution

逆向的dp
```c++
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m= dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n-1][m-1] = max(1, 1-dungeon[n-1][m-1]);
        for(int i=n-2;i>-1;--i) dp[i][m-1] = max(1, dp[i+1][m-1] - dungeon[i][m-1]);
        for(int j = m-2;j>-1 ;j--) dp[n-1][j] = max(1, dp[n-1][j+1] - dungeon[n-1][j]);
        
        for(int i=n-2;i>-1;i--){
            for(int j=m-2;j>-1;j--){
                dp[i][j] = min(
                    max(1,dp[i+1][j] - dungeon[i][j]),
                    max(1, dp[i][j+1] - dungeon[i][j])
                        );
            }
        }
        
        
        return dp[0][0];
        
    }
};
```

## analysis
- time complexity `O(nm)`
- space complexity `O(nm)`