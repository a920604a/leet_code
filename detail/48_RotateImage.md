---
title: 48. Rotate Image
tags: 
    - Matrix
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/rotate-image/)

## solution
#### option 1 
先對陣列以行為單位做`reverse`，再逐一對角線對調。反之亦然

```c++
class Solution {
public:
    void swap(int &a, int &b){
        a = a^b;
        b = a^b;
        a = a^b;
    }
    void reverse(vector<int> & nums){
        int l = 0 , r = nums.size()-1;
        while(l<r) swap(nums[l++], nums[r--]);
    }
    void rotate(vector<vector<int>>& matrix) {
        //先對角線對調，在每列reverse
        
        //  1   2   3
        //  4   5   6
        //  7   8   9
        
        //  1   4   7
        //  2   5   8
        //  3   6   9
        
        //  7   4   1
        //  8   5   2
        //  9   8   7
        
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i=0;i<n;++i){
            for(int j=i+1;j<m;++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;++i) reverse(matrix[i]);
        
    }
};
```
#### option 2
```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;++i){
            for(int j=i;j<n-1-i;++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
        
    }
};
```
## analysis
- time complexity `O(n^2)`
- space complexity `O(1)`