---
title: 53. Maximum Subarray
tags:  
    - dp
    - Kadane's Algo 
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-subarray/)

給定一陣列，求出總和最大連續子陣列，並返回其值


## Solution

#### option 1 - Divide and Conquer


```c++
class Solution {
public:
    int Divide(vector<int>&nums, int l, int r){
        if(l>=r) return nums[l];
        int mid = l+ (r-l)/2;
        int lmax = Divide(nums, l, mid-1);
        int rmax = Divide(nums, mid+1, r);
        int mmax = nums[mid];
        int temp = nums[mid];
        
        for(int i=mid-1;i>=l;--i){
            temp+=nums[i];
            mmax = max(temp, mmax);
        }
        temp = mmax;
        for(int i=mid+1;i<=r;++i){
            temp+=nums[i];
            mmax = max(temp, mmax);
        }
        return max(max(lmax, rmax), mmax);
    }
    int maxSubArray(vector<int>& nums) {
        return Divide(nums, 0, nums.size()-1);
    }
};
```
#### option 2 - dp

維護一個dp 紀錄遍歷至當前的最大的子陣列和。

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //      -1  1   -3  4   -1  2   1   -5  4
        //dp    -1  1   -2  4   3   5   6   1   5
        
        int n = nums.size(), ret = nums[0];
        vector<int>dp(n, INT_MIN);
        dp[0] = nums[0];
        for(int i=1;i<n;++i){
            dp[i] = max(dp[i-1]+ nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
```
#### option 3 - Kadane’s Algorithm

reduce dp，用變數取代dp array

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local = 0, global = INT_MIN;
        for(int n:nums){
            local = max(local+n, n);
            global = max(local, global);
        }
        return global;
        
    }
};
```
## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - speed complexity `O(n)`
- option 3
    - time complexity `O(n)`
    - speed complexity `O(1)`
