---
title: 785. Is Graph Bipartite?
tags:  
    - bfs
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/is-graph-bipartite/)
## solution 
#### option 1 - dfs
```c++
class Solution {
private:
    bool ok = true;
    vector<bool> color, visited;
    void traverse(vector<vector<int>> graph, int v){
        // 已經確定不是二分圖了
        if(!ok) return;
        visited[v] = true;
        for(int w:graph[v]){
            // 拜訪鄰居 w
            if(!visited[w]){
                color[w] = !color[v];
                traverse(graph, w);
            }
            else{
                // 鄰居w 已經被拜訪過了
                if(color[w] == color[v]){
                    ok = false;
                }
            }
        }
    }
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<bool>(n, false);
        visited = vector<bool>(n, false);
        for(int v=0;v<n;++v){
            if(!visited[v]){
                traverse(graph, v);
            }
        }
        return ok;
    }
};
```
#### option 2 - bfs
