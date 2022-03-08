---
title: 153. Find Minimum in Rotated Sorted Array

tags:  
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

## solution
#### option 1 - Binary Search

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int l = 0, r = n-1;
        int ret = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            ret = min(nums[mid], ret);
            // 右半部遞增
            if(nums[mid] < nums[r] ) r = mid-1;
            // 左半部遞增
            else l = mid+1;
        }
        return ret;
    }
};

```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`