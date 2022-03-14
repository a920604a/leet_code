---
title: 33. Search in Rotated Sorted Array

tags:  
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/search-in-rotated-sorted-array/)

在有序陣列，旋轉後，搜尋target的index
各元素唯一
## solution

- 因為是原先是有順序的，要嘛左半部遞增，要嘛右半部遞增
- 假如右半部遞增，target剛好落在右半部，則向右搜尋，反之向左搜尋
- 假如左半部遞增，target剛好落在左半部，則向左搜尋，反之向右搜尋

#### option 1 Brute force
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i] == target) return i;
        }
        return -1;
    }
};
```

#### option 2 Binary Search 
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            // 右半部遞增
            if(nums[mid] < nums[r]){
                if(nums[mid]<target && target <=nums[r]) l=mid+1;
                else r = mid-1;
            }
            //左半部遞增
            else{
                if(nums[l]<=target && target < nums[mid]) r =mid-1;
                else l =mid+1;
            }
        }
        return -1;
    }
};
```
## analysis
- option 1
    - time complexity `O(n)`
    - speed complexity `O(1)`
- option 2
    - time complexity `O(logn)`
    - speed complexity `O(1)`