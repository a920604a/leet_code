---
title: 695. Max Area of Island
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/max-area-of-island/)


## solution
#### option 1 - dfs
```c++
class Solution {
public:
    void dfs(vector<vector<int>> & grid, int i, int j, int & area){
        
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || j< 0 || i>n-1 || j>m-1 || grid[i][j] == 0 ) return;
        grid[i][j] = 0;
        area++;
        dfs(grid, i+1, j, area);
        dfs(grid, i-1, j, area);
        dfs(grid, i, j+1, area);
        dfs(grid, i, j-1, area);        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ret = 0;
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                int area = 0;
                dfs(grid, i, j, area);
                ret= max(ret, area);
            }
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n*m)`
- space complexity `O(n*m)`