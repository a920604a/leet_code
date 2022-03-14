---
title: 154. Find Minimum in Rotated Sorted Array II

tags:  
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

元素可能重複

## solution
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            // 代表最小值會在 [mid+1, r] 之間
            if(nums[mid] > nums[r]) l = mid+1;
            // 下次搜尋區間
            else if(nums[mid] < nums[r] ) r = mid;          
            else r--;
        }
        return nums[l];
    }
};
```
## analysis
- time complexity `O(logn)`
- space complexity `O(1)`