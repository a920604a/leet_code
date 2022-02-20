---
title: 167. Two Sum II - Input Array Is Sorted
tags:  
    - Binary Search
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

## solution


#### option 1 - Two Pointers
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l =0, r=n-1;
        while(l<r){
            if(numbers[l] + numbers[r] == target) return {l+1, r+1};
            else if(numbers[l] + numbers[r] < target) l++;
            else r--;
            
        }
        return {-1,-1};
        
    }
};
```
#### option 2 - Binary Search
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // use only constant extra space
        vector<int>  ret;
        int n = numbers.size();
        for(int i=0;i<n-1; ++i){
            int l =i+1, r = n-1;
            // Two pointers
            while(l<=r){
                int mid = l+ (r-l)/2;
                if(numbers[i] + numbers[mid] == target) return {i+1, mid+1};
                else if(numbers[i] + numbers[mid] < target)  l= mid+1;
                else r = mid-1;
            }
        }
        return {-1,-1};
    }
};
```

## analysis
- option 1
    - times complexity `O(n)`
    - space complexity `O(1)`
- option 2
    - times complexity `O(nlogn)`
    - space complexity `O(1)`