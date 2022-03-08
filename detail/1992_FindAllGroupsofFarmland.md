---
title: 1992. Find All Groups of Farmland

tags:  
    - backtracking
categories: leetcode

comments: false
---


## [problem](https://leetcode.com/problems/find-all-groups-of-farmland/)

## solution

```c++
class Solution {
public:
    int top , left, bottom , right;
    void traverse(vector<vector<int>>& land, int i, int j){
        int n = land.size(), m=land[0].size();
        if(i<0 || j< 0 || i>n-1 || j>m-1 || land[i][j] == 0) return;
        land[i][j] = 0;
        top = min(top, i);
        left = min(left, j);
        right = max(right,j);
        bottom = max(bottom, i);
        traverse(land, i+1, j);
        traverse(land, i-1, j);
        traverse(land, i, j+1);
        traverse(land, i, j-1);
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ret;
        int n = land.size(), m=land[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(land[i][j] ==1){
                    top  = i;
                    left = j;
                    right = j;
                    bottom = i;
                    ret.push_back({i,j});
                    traverse(land, i, j);
                    ret.back().push_back(bottom);
                    ret.back().push_back(right);
                }
            }
        }
        return ret;
        
        
    }
};
```

