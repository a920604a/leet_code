---
title: 1254. Number of Closed Islands
tags:  
    - backtracking
    - bfs
    - Union Find
categories: leetcode

comments: false
---

## [problem](https://leetcode.com/problems/number-of-closed-islands/)

## solution
先將周圍島嶼淹沒，再去算剩下島嶼數

#### option 1 - dfs
```c++
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || grid[i][j] == 1 ) return;
        
        grid[i][j] = 1;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;++i){
            dfs(grid,i,0);
            dfs(grid, i, m-1);
        }
        for(int j=0;j<m;++j){
            dfs(grid,0,j);
            dfs(grid, n-1, j);
        }
        int count = 0;
        for(int i=1;i<n-1;++i){
            for(int j = 1 ;j<m-1;++j){
                if(grid[i][j] == 0){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
```
#### option 2 - bfs

## analysis
- time complexity `O(m*n)`
- space complexity `O(m*n)`