---
title: 912. Sort an Array
tags:  
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sort-an-array/)


## solution

#### option 1 - merge sort
```c++
class Solution {
public:
    void merge(vector<int> & nums, int l, int mid , int r){
        if(l>=r) return ;
        vector<int> left(nums.begin()+l, nums.begin()+mid+1);
        vector<int> right(nums.begin()+mid+1, nums.begin()+r+1);
        int i=0, j=0, k=l, n=left.size(), m = right.size();
        while(i<n && j<m){
            if(left[i] < right[j]) nums[k++] = left[i++];
            else nums[k++] = right[j++];
        }
        while(i<n) nums[k++] = left[i++];
        while(j<m) nums[k++] = right[j++];
        
        
    }
    void mergeSort(vector<int>& nums, int l, int r){
        
        if(l<r){
            int mid = l + (r-l)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);
            merge(nums, l,mid, r);
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};
```

#### option 2 - quick sort

```c++

class Solution {
public:
    int partition(vector<int>& nums, int l, int r){
        
        int pivot = nums[r];
        int j = l-1;
        for(int i=l;i<r;++i){
            if(nums[i] <pivot ){
                swap(nums[++j], nums[i]);
            }
        }
        
        swap(nums[++j], nums[r]);
        return j;
    }
    void quickSort(vector<int>& nums, int l, int r){
        if(l<r){
            
            int p = partition(nums, l, r);
            quickSort(nums, l, p-1);
            quickSort(nums, p+1, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

```
## analysis

- time complexity `O(nlogn)`
- space complexity `O(n)`
