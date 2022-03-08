---
title: 154. Find Minimum in Rotated Sorted Array II

tags:  
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)


## solution
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            // 左半部遞增
            if(nums[mid] >  nums[r]) l = mid+1;
            // 右半部遞增
            else if(nums[mid] < nums[r]) r = mid;
            else r--;
        }
        return nums[l];
    }
};
```


## analysis
- time complexity `O(logn)`
- space complexity `O(1)`