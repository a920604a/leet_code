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
        int n =arr.size();
        if(n<3) return false;
        int l =0 , r = n-1;
        while(l<r && arr[l] < arr[l+1]) l++;
        while(l<r && arr[r-1] > arr[r]) r--;
        return (l!=0) && (r!=n-1) &&(l==r);
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`