---
title: 200. Number of Islands
tags:  
    - backtracking
    - bfs
    - Union Find
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/number-of-islands/)

## solution

#### option 1 - backtracking
將拜訪過的位置，原地修改其陣列的值為 `0`

```c++
class Solution {
public:
    void dfs(vector<vector<char>> & grid,int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || grid[i][j] =='0') return;
        
        grid[i][j] = '0';
        dfs(grid, i-1,j);
        dfs(grid, i+1,j);
        dfs(grid, i,j-1);
        dfs(grid, i, j+1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
        
    }
};
```


#### option 2 bfs

```c++
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size(),count= 0;
        queue<vector<int>> q;
        for(int i=0;i<n;++i){
            for(int j = 0 ; j<m ;++j){
                
                if(grid[i][j] == '1'){
                    count++;
                    q.push({i,j});
                    while(!q.empty()){
                        vector<int> cur = q.front();
                        q.pop();
                        int x = cur[0], y = cur[1];
                        if(x< 0 || y<0 || x>n-1 || y>m-1 || grid[x][y] == '0') continue;
                        grid[x][y] = '0';
                        push({x+1,y});
                        q.push({x-1,y});
                        q.push({x,y+1});
                        q.push({x,y-1});
                    }
                }
                
            }
        }
        return count;
    }
};
```
#### option 3 - *Union Find
## analysis
- option 1 
    - time complexity `O(n*m)` 
    - space complexity `O(n*m)`
- option 2 
    - time complexity `O(n*m)` 
    - space complexity `O(n*m)`
