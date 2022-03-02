---
title: 77. Combinations

tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/combinations/)

## solution

```c++
class Solution {
public:
    vector<vector<int>> ret;
    void traverse(int n, int k, vector<int> & path, int start){
        // 終止條件
        if(path.size() ==k){
            ret.push_back(path);
            return;
        }
        
        for(int i=start;i<=n;++i){
            path.push_back(i);
            // [2,4] OK , [4,2] not OK -> 只允許遞增，避免重複
            traverse(n,k,path, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        traverse(n,k,path, 1);
        return ret;
    }
};
```