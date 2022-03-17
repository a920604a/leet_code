---
title: 215. Kth Largest Element in an Array
tags:  
    - heap
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/kth-largest-element-in-an-array/)

## solution

#### option 1 - sort
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};
```
#### option 2 - heap
- version 1
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;    
        for(int n:nums) pq.push(n);
        int ret ;
        while(k--){
            ret = pq.top();
            pq.pop();
        }
        return ret;
    }
};
```
- version 2
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int n:nums){
            pq.push(n);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
```

#### option 3 - quick sort
```c++
class Solution {
public:
    int getKth(int k, vector<int> &nums, int start, int end){
        int pivot = nums[end];
        int left = start, right = end;
        while(1){
            while(left< right && nums[left]<pivot) left++;
            while(left<right && nums[right]>=pivot) right--;

            // found it 
            if(left==right) break;
            swap(nums[left], nums[right]);
        }
        swap(nums[left], nums[end]);
        
        if(left+1 == k) return pivot;
        else if(left+1 > k) return getKth(k, nums, start, left-1);
        else return getKth(k, nums, left+1, end);
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(k< 1 || nums.empty()) return 0;
        return getKth(nums.size()-k+1, nums, 0, nums.size()-1);
        
    }
};
```
## analysis

- option 1 - sort 
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
- option 2 - heap
    - time complexity `O(nlogk)`
    - space complexity `O(k)`
- option 3 - quick sort
    - time complexity `O(nlogn)` on average,`O(n^2)` on worse case
    - space complexity `O(n)`

