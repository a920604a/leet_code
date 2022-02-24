---
title: 59. Spiral Matrix II
tags: 
    - Matrix
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/spiral-matrix-ii/)

## solution 
維護一組陣列，控制下一步要走的方向

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n,0));
        int cur = 1;
        int i =0, j=-1, a=0;
        vector<int> d = {0,1,0,-1};
        vector<bool> visited(n*n, false);
        for(int _=0;_<n*n;++_){
            
            int x = i+d[a%4], y = j+d[(a+1)%4];
            while( x<0 || x>n-1 || y<0 || y>n-1 || visited[x*n+y]){
                a++;
                x = i+d[a%4];
                y = j+d[(a+1)%4];
            }
            
            visited[x*n+y] = true;
            ret[x][y] = cur++;
            i = x, j =y;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n^2)`
- space complexity `O(n^2)`