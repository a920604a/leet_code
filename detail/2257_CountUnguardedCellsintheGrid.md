---
title: 2257. Count Unguarded Cells in the Grid
tags:
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/)

## solution

```c++
class Solution {
public:
    vector<vector<int>> map;
    void dfs(int m, int n,int i, int j, vector<int>& dirs){
        i+=dirs[0];
        j+=dirs[1];
        if(i<0 || j<0 || i>m-1 || j>n-1) return ;
        if(map[i][j] == 0) return;
        map[i][j] = 2;
        dfs(m,n,i,j, dirs);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        map = vector<vector<int>>(m, vector<int>(n,1));
        vector<vector<int>> dirs = {
            {0,1},{1,0},{0,-1},{-1,0}
        };
        // guards and Walls is zero
        // the cell is guarded is two
        for(auto g:guards) map[g[0]][g[1]] = 0;
        for(auto w:walls) map[w[0]][w[1]] = 0;
        for(auto guard:guards){
            int i = guard[0], j= guard[1];
            for(auto &dir:dirs) dfs(m,n,i,j,dir);
        }
        
        int count = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(map[i][j] == 1) count++;
            }
        }
        return count;
    }
};
```

## analysis