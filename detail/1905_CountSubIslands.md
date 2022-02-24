---
title: 1905. Count Sub Islands

tags:  
    - backtracking
    - bfs
    - Union Find
categories: leetcode

comments: false
---

## [problem](https://leetcode.com/problems/count-sub-islands/)

## solution

```c++
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i< 0 || j<0 || i>n-1 || j>m-1 ||grid[i][j] == 0  ) return; 
        grid[i][j] = 0;
        dfs(grid,i-1,j);
        dfs(grid,  i+1,j);
        dfs(grid, i,j-1);
        dfs(grid, i,j+1);
        
    
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                // 這個島於肯定不是子島嶼，淹沒
                if(grid1[i][j] == 0 && grid2[i][j] == 1) dfs(grid2, i, j);
            }
        }
        
        int count = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;++j){
                if(grid2[i][j] == 1){
                    count++;
                    dfs(grid2, i, j);
                }
            }
        }
        return count;
        
    }
};
```

## analysis
- time complexity `O(n*m)`
- space complexity `O(n*m)`