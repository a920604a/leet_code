---
title: 162. Find Peak Element
tags:  
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-peak-element/)
## solution
#### option 1 
```c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // burce force
        int n = nums.size();
        if(n==1) return 0;
        for(int i=1;i<n-1; ++i){
            if(nums[i] > nums[i-1] && nums[i]>nums[i+1]) return i;
        }
        if(nums[0] >nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        return -1;
    }
};
```
#### option 2 *Binary Search
```c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l= 0, r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]< nums[mid+1]) l =mid+1;
            else r = mid;
        }
        return r;
    }
};
```
## analysis
- option 1
- time complexity `O(n)` `O(logn)`
- space complexity `O(1)`