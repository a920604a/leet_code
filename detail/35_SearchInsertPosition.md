---
title: 35. Search Insert Position
tags:  
    - Binary Search
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/search-insert-position/)


## solution

#### option 1 - linear search
```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ret = -1, n= nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]>=target) return i;
        }
        return n;
    }
};
```

#### option 2 - binary search

- normal version

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), l=0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] ==target) return mid;
            else if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return l ;
        
    }
};
```
- left bound
```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), l=0,r=n;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid] ==target) return mid;
            else if(nums[mid] < target) l = mid+1;
            else r = mid;
        }
        return l ;
        
    }
};
```

## analysis
- option 1
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(logn)`
    - space complexity `O(1)`