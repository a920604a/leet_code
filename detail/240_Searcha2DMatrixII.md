---
title: 240. Search a 2D Matrix II
tags:  
    - Two Pointers
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/search-a-2d-matrix-ii/)

## solution 

#### option 1 - Two Pointers
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i= n-1, j = 0;
        while(i>-1 && j>-1 && i<n && j<m){
            int cur = matrix[i][j];
            if(cur == target) return true;
            else if(cur<target) j++;
            else i--;
        }
        return false;
    }
};
```
#### option 2 - Binary Search
```c++
class Solution {
public:
    bool search(vector<int> &nums, int target){
        int l =0 , r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid]<target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i=0;i<n;++i){
            if(search(matrix[i], target)) return true;
        }
        return false;
    }
};
```


## analysis
- option 1 - Two Pointers
    - time complexity `O(n+m)`
    - space complexity `O(1)`
- option 2 - Binary Search
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
