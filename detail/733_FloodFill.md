---
title: 733. Flood Fill
tags:  
    - backtracking
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/flood-fill/)

## solution

#### option 1 - dfs
```c++
class Solution {
public:
    void dfs(vector<vector<int>> & image, int i, int j, int newColor, int oldColor){
        int n = image.size(), m=image[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || image[i][j] !=oldColor) return ;
        image[i][j] = newColor;
        
        dfs(image, i-1, j, newColor, oldColor);
        dfs(image, i+1, j, newColor, oldColor);
        dfs(image, i, j-1, newColor, oldColor);
        dfs(image, i, j+1, newColor, oldColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc]) return image;
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
        
    }
};

```

#### option 2 - bfs
```c++
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] == newColor) return image;
        int n= image.size(), m = image[0].size();
        int oldColor= image[sr][sc];
        queue<vector<int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            int i = cur[0], j = cur[1];
            if(i<0 || j<0 || i>n-1 || j>m-1 || image[i][j] != oldColor) continue;
            image[i][j] = newColor;
            q.push({i+1,j});
            q.push({i,j+1});
            q.push({i-1,j});
            q.push({i,j-1});            
        }
        return image;
        
    }
};

```
## analysis
- option 1 - dfs
    - time complexity `O(n*m)`
    - space complexity `O(n*m)`
- option 2 - bfs
    - time complexity `O(n*m)`
    - space complexity `O(n*m)`