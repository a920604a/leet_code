---
title: 797. All Paths From Source to Target
tags:  
    - Graph
    - backtracking
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/all-paths-from-source-to-target/)

## solution
```c++
class Solution {
public:
    void traverse(vector<vector<int>>& graph, int cur, vector<int>& path, vector<vector<int>>& ret){
        // 添加節點至路徑
        path.push_back(cur);
        if(path.back() == graph.size()-1){
            // 抵達終點
            ret.push_back(path);
            path.pop_back();
            return;
        }
        // 遞迴每個相鄰節點
        for(int  neighbor:graph[cur]){
            traverse(graph, neighbor, path, ret);
            
        }
        
        path.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ret;
        vector<int> path;
        traverse(graph, 0, path, ret);
        return ret;
    }
};

```



```c++
class Solution {
public:
    vector<vector<int>>  ret;
    void backtracking(vector<vector<int>>& graph, vector<int> & path, int cur){
        path.push_back(cur);
        if(path.back() == graph.size()-1){
            ret.push_back(path);
            return;
        }
        
        for(int nei : graph[cur]){
            backtracking(graph, path, nei);
            path.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        backtracking(graph, path, 0);
        return ret;
        
    }
};
```
## analysis
- time complexity `O(V+E)`
- space complexity `O(V)`