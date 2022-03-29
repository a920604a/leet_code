---
title: 74. Search a 2D Matrix
tags:  
    - Two Pointers
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/search-a-2d-matrix/submissions/)


## solution
#### option 1 - Two Pointers
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m=matrix[0].size();
        int i=0, j = m-1;
        int cur;
        while(i>-1 && i<n && j>-1 && j<m){
            cur = matrix[i][j];
            if(cur == target) return true;
            else if(cur<target) i++;
            else j--;
        }
        return false;
    }
};
```
#### option 2 - Binary Search

```c++
class Solution {
public:
    bool BinarySearch(vector<int> & nums, int target){
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) l = mid+1;
            else r = mid -1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m= matrix[0].size();
        for(int i=0;i<n;++i){
            if(target >=matrix[i][0] && target<= matrix[i][m-1]){
                if(BinarySearch(matrix[i], target)) return true;
            }
        }
        return false;
    }
};
```


#### option 3 - Binary Search
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n*m-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(matrix[mid/m][mid%m] == target) return true;
            else if(matrix[mid/m][mid%m] > target) r = mid-1;
            else l = mid+1;
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
- option 3 - Binary Search
    - time complexity `O(log(n+m))`
    - space complexity `O(1)`