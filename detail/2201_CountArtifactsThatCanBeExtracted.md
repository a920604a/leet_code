---
title: 2201. Count Artifacts That Can Be Extracted
tags:
    - hash table
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/count-artifacts-that-can-be-extracted/)


## solution
```c++
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        vector<vector<int>> map(n, vector<int>(n,0));
        int m = artifacts.size();
        vector<int> area(m+1,0);
        for(int i=0, j = 1;i<m;++i, j++){
            for(int x = artifacts[i][0];x<=artifacts[i][2] ; x++){
                for(int y = artifacts[i][1];y<=artifacts[i][3] ;y++) map[x][y] = j;
            }
            area[j] = (artifacts[i][3]-artifacts[i][1]+1)*(artifacts[i][2]-artifacts[i][0]+1);
        }
        for(auto d :dig){
            int i=d[0], j = d[1];
            int color = map[i][j];
            
            area[color]-=1;
            
        }
        int count = 0;
        for(int i=1;i<m+1;++i){
            count+=(area[i]==0);
        }
        return count;
        
    }
};
```
## analysis
- time complexity `O(m*n*n)`
- space complexity `O(n*n)`