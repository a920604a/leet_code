---
title: 1283. Find the Smallest Divisor Given a Threshold
tags:
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)
## solution
- version 1
```c++
class Solution {
public:
    int func(vector<int> & nums, int d){
        int sum = 0;
        for(int n:nums){
            sum+=n/d;
            if(n%d) sum++;
        }
        return sum;
        
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //  1   2   5   9
        // divisor = 1  2   3   4   5   6   7   8   9
        // sum =     17 10  7   7   5   5   5   5   5
        
        int l = 1, r = 1;
        for(int n :nums) r = max(r, n);
        while(l<=r){
            int mid = l + (r-l)/2;
            int sum = func(nums, mid);
            if(sum > threshold) l = mid+1;
            else if(sum<= threshold) r = mid-1;
        }
        return l;
    }
};
```

- version 2
```c++
class Solution {
public:
    int func(vector<int> & nums, int d){
        int sum = 0;
        for(int n:nums){
            sum+=n/d;
            if(n%d) sum++;
        }
        return sum;
        
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //  1   2   5   9
        // divisor = 1  2   3   4   5   6   7   8   9
        // sum =     17 10  7   7   5   5   5   5   5
        
        int l = 1, r = 1;
        for(int n :nums) r = max(r, n);
        while(l<r){
            int mid = l + (r-l)/2;
            int sum = func(nums, mid);
            if(sum > threshold) l = mid+1;
            else if(sum<= threshold) r = mid;
        }
        return l;
    }
};
```
## analysis
- time complexity `O(logn)`
- space complexity `O(1)`
