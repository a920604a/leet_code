---
title: 378. Kth Smallest Element in a Sorted Matrix
tags:
    - heap
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

## solution 

#### option 1 - STL to store
```c++
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix , int k) {
        vector<int> vec;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0 ;i<n;++i){
            for(int j = 0;j<m;++j) vec.push_back(matrix[i][j]);
        }
        sort(vec.begin(), vec.end());
        return vec[k-1];
    }
};
```


#### option 2 - heap
```c++
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix , int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0 ;i<n;++i){
            for(int j = 0;j<m;++j) pq.push(matrix[i][j]);
        }
        k--;
        while(k--) pq.pop();
        return pq.top();
    }
};
```
#### option 3- Binary Search
```c++
class Solution {
public:
    int lower_bound(vector<int> & nums, int target){
        //left lower
        int l = 0, r = nums.size();
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] <= target ) l = mid+1;
            else r = mid;
        }
        return l ;
    }
    int kthSmallest(vector<vector<int>>& matrix , int k) {
        
        int n = matrix.size(), m = matrix[0].size();
        int left = matrix[0][0], right = matrix[n-1][m-1];
        while(left<right){
            int mid = left + (right-left)/2;
            int cnt = 0;
            // cnt 計算陣列有多少數字小於等於mid
            for(int i=0;i<n;++i){
                cnt+=lower_bound(matrix[i], mid);
            }
            if(cnt > k) right = mid;
            else if(cnt<k) left = mid + 1;
            else right = mid;
            
        }
        return left;
    }
};
```


## analysis
- option 1
    - time complexity `O(n^2)`
    - space `O(n)`
- option 2 
    - time complexity `O(n^2)`
    - space complexity `O(n)`