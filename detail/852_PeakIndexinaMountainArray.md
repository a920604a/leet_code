---
title: 852. Peak Index in a Mountain Array
tags:  
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
## solution
#### option  1 brute force
```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        for(int i=1;i<n-1;++i){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) return i;
        }
        return -1;
        
    }
};
```

#### option 2
```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r =n-1;
        while(l+1<n && arr[l] < arr[l+1]) l++;
        return l;
        
    }
};
```
#### option 3 Binary Search
```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0, r = arr.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(arr[mid]<arr[mid+1]) l = mid+1;
            else r = mid;
        }
        return r;
    }
};
```
## analysis
- time complexity `O(n)` `O(logn)`
- space complexity `O(1)`