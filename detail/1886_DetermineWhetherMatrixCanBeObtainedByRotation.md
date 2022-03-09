---
title: 1886. Determine Whether Matrix Can Be Obtained By Rotation
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)


## solution
```c++
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int t =3;
        int n = mat.size();
        if(mat == target) return true;
        while(t--){
            // rotate one time
            reverse(mat.begin(), mat.end());
            
            for(int i=0;i<n;++i){
                for(int j=i+1;j<n;++j){
                    swap(mat[i][j], mat[j][i]);
                }
            }
            if(mat == target) return true;
        }
        return false;
    }
};
```


## analysis
- time complexity `O(n^2)`
- space complexity `O(1)`
