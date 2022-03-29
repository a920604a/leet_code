---
title: 54. Spiral Matrix
tags: 
    - Matrix
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/spiral-matrix/)

## solution 
維護一組陣列，控制下一步要走的方向

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        vector<int> d = {0,1,0,-1};
        int n= matrix.size(), m= matrix[0].size();
        vector<bool> visited(m*n,false);
        int i = 0, j=-1, a = 0;
        for(int _ = 0;_<n*m; ++_){
            
            int x = i+d[a%4], y = j+d[(a+1)%4];
            while(x < 0 || y<0 || x>n-1 || y>m-1 || visited[x*m+y]){
                a++;
                x = i+d[a%4];
                y = j+d[(a+1)%4];
            }
            visited[x*m+y] = true;
            ret.push_back(matrix[x][y]);
            i = x;
            j = y;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n*m)`
- space complexity `O(n*m)`