---
title: 1091. Shortest Path in Binary Matrix
tags:  
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/shortest-path-in-binary-matrix/)
## solution 
```c++
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        queue<vector<int>> q;
        q.push({0,0});
        vector<vector<int>> neighbor = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},{0,1},
            {1,-1},{1,0},{1,1}
        };
        int step = 1, n=grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                auto p = q.front();
                q.pop();
                if(p[0] == n-1 && p[1] == m-1) return step;
                for(vector<int> &nei:neighbor){
                    int x = p[0]+nei[0], y = p[1]+nei[1];
                    if(x>-1 && x<n && y>-1 && y<m && grid[x][y] == 0 && !visited[x][y] ) {
                        q.push({x,y});
                        visited[x][y] = true;
                    }
                    
                }
            }
            
            step++;
        }
        return -1;
        
    }
};
```
