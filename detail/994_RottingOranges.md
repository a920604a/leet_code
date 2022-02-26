---
title: 994. Rotting Oranges
tags:  
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/rotting-oranges/)

## solution

```c++
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        // 紀錄新鮮的橘子個數 (grid[i][j] = 1)
        int fresh_cnt = 0;
        int n= grid.size(), m = grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh_cnt++;
            }
        }
        
        vector<vector<int>> dirs = {{-1,0}, {0,-1},{1,0},{0,1}};
        int step = 0;
        while(!q.empty() && fresh_cnt){
            int size =q.size();
            for(int i=0;i<size ; ++i){
                vector<int> p = q.front();
                q.pop();
                for(auto d:dirs){
                    int x= p[0]+d[0], y = p[1] + d[1];
                    if(x< 0 || y<0 || x>n-1 || y>m-1  || grid[x][y] !=1) continue;
                    grid[x][y] = 2;
                    q.push({x,y});
                    // 拜訪過所以腐爛，所以減一
                    
                    fresh_cnt--;
                }
            }
            step++;
        }
        // 如果還有新鮮橘子
        if(fresh_cnt>0) return -1;
        return step;
        
    }
};
```


## analysis
- time complexity `O(n*m)`
- space complexity `O(n*m)`