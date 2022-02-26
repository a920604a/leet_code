---
title: 941. Valid Mountain Array
tags: 
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/valid-mountain-array/)

## solution
只會有一個peak

```c++
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        //  0   1   2   1   2 => false
        int i=0, j=n-1;
        while(i<j && arr[i+1] > arr[i]) i++;
        while(i<j && arr[j-1] > arr[j]) j--;
        if(i==0 || j==n-1) return false;
        return i==j?true:false;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`