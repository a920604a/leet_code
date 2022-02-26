---
title: 542. 01 Matrix
tags:  
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/01-matrix/)


## solution

- bfs -> time out
```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // dfs seem not to work
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ret(n, vector<int>(m, INT_MAX));
        
        queue<vector<int>> q;
        vector<int> d = {0,1,0,-1};
        for(int i=0;i<n;++i){
            for(int  j =0;j<m;++j){
                
                if(mat[i][j] == 0){
                    // bfs can find the shortest path
                    q.push({i,j});
                    int depth = 0;
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    while(!q.empty()){
                        int size = q.size();
                        for(int _=0;_<size ; ++_){
                            vector<int> p = q.front();
                            q.pop();
                            int x = p[0],  y=p[1];
                            if(x<0 || y<0 || x>n-1 || y>m-1 || visited[x][y]) continue;
                            visited[x][y] = true;
                            if(mat[x][y] ==1) {
                                ret[x][y] = min(ret[x][y], depth);
                            }
                            q.push({x-1, y});
                            q.push({x+1, y});
                            q.push({x, y-1});
                            q.push({x, y+1});
                             
                        }
                        depth++;
                        
                    }
                    ret[i][j] = 0;
                    
                }
                
            }
        }
        return ret;
        
    }
};
```

#### option 1
將 `mat[i][j]=1` 的地方先收集起來
```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m=mat[0].size();
        vector<vector<int>> ret = mat;
        queue<vector<int>> q;
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(mat[i][j] == 0) q.push({i,j});
                else ret[i][j] = -1;
            }
        }
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        while(!q.empty()){
            vector<int> p = q.front();
            q.pop();
            
            for(auto d:dirs){              
                int x= p[0]+d[0], y = p[1] +d[1];
                if(x<0 || y<0 || x>n-1 || y>m-1 || ret[x][y]!=-1) continue;
                // 記住父節點，並從他出發
                ret[x][y] = 1+ ret[p[0]][p[1]];
                q.push({x,y});
            }
        }
        return ret;
        
    }
};
```

## analysis