---
title: 34. Find First and Last Position of Element in Sorted Array
tags:  
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)


## solution


```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] < target) l = mid+1;
            else r= mid - 1;
        }
        if(l<0 || l>n-1 || nums[l]!=target) return {-1,-1};
        int j = l;
        while(j+1<n && nums[j] == nums[j+1]) j++;
        return {l,j};
    }
};
```
- lower bound

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int l = 0 , r = nums.size();
        while(l<r){
            int mid = l +(r-l)/2;
            if(nums[mid]>=target) r= mid;
            else l = mid+1;
        }
        if(l<0 || l>nums.size()-1 || nums[l]!=target) return {-1,-1};
        r = l;
        while(r<nums.size()-1 && nums[r+1] == nums[l] ) r++;
        return {l,r};
    }
};
```## analysis
- time complexity `O(logn)`
- space complexity `O(1)`
