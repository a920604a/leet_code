---
title: 329. Longest Increasing Path in a Matrix
tags:  
    - backtracking
    - bfs
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)

## solution
- dfs , TLE
```c++
class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>> & matrix, int i, int j, int len, int &ans){
        ans = max(ans ,len );
        
        int n = matrix.size(), m = matrix[0].size();
        for(auto d:dirs){
            int x = i +d[0], y = j+d[1];
            if(x>=0 && x<n && y>=0 && y<m && matrix[x][y] > matrix[i][j]) dfs(matrix,x , y, len+1, ans);
        }
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m= matrix[0].size();
        vector<vector<int>> path(n, vector<int>(m,1));
        // 因為最短為 1x1
        int longpath = 1;
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                dfs(matrix, i,j,1, path[i][j]);
                longpath = max(longpath,  path[i][j]);
            }
        }
        return longpath;
    }
};
```
#### option 1 -  dfs + memo
```c++
class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> memo;
    int dfs(vector<vector<int>> & matrix, int i, int j){
        if(memo[i][j]> 0) return memo[i][j];
        int n = matrix.size(), m = matrix[0].size();
        for(auto d:dirs){
            int x = i +d[0], y = j+d[1];
            if(x>=0 && x<n && y>=0 && y<m && matrix[x][y] > matrix[i][j]) {
                memo[i][j] =  max(memo[i][j], dfs(matrix,x , y));
            }
        }
        return ++memo[i][j];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m= matrix[0].size();
        vector<vector<int>> path(n, vector<int>(m,1));
        memo = vector<vector<int>>(n, vector<int>(m,0));
        int longpath = 1;
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                int ret = dfs(matrix, i,j);
                longpath = max(longpath,  ret);
            }
        }
        return longpath;
    }
};
```
#### option 2 - bfs , maybe TLE
```c++
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ret = 1;
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(dp[i][j]>0) continue;
                queue<pair<int,int>> q({{i,j}});
                int cnt = 1;
                while(!q.empty()){
                    cnt++;
                    int size = q.size();
                    for(int k = 0;k<size;++k){
                        auto t = q.front();q.pop();
                        for(auto d:dirs){
                            int x = t.first + d[0],  y= t.second+d[1];
                            if(x<0 || x>n-1 || y<0 || y>m-1 || matrix[x][y] <= matrix[t.first][t.second] ||  cnt <= dp[x][y]) continue;
                            dp[x][y] = cnt;
                            ret = max(ret, cnt);
                            q.push({x,y});
                            
                        }
                    }
                }
            }
        }
       return ret; 
    }
};
```