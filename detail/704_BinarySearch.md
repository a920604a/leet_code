---
title: 704. Binary Search
tags:  
    - Binary Search
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/binary-search/)


## solution

- normal version
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]< target) l =mid+1;
            else r= mid-1;
        }
        return -1;
    }
};
```
- left bound
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]< target) l =mid+1;
            else r= mid;
        }
        if(l<n && nums[l] == target) return l;
        return -1;
    }
};
```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`
