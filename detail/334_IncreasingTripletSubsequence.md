---
title: 334. Increasing Triplet Subsequence
tags:
    - greedy
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/increasing-triplet-subsequence/)

## solution
- dp and TLE
> 300. Longest Increasing Subsequence
```c++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        // subsequence ，未必連續
        // 最長遞增子序列
        //  20  100 10  12  5   13
        //  1   1   1   1   1   1
        //  1   2   1   2   1   3
        
        vector<int> dp(n,1);
        for(int i=1;i<n;++i){
            for(int j = 0;j<i;++j){
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
            if(dp[i] == 3) return true;   
        }
        return false;
    }
};
```
#### option 1 - dp
維護兩陣列
> 152 Maximum Product Subarray
> 42 Trapping Rain Water
```c++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> mx(n, INT_MIN), mn(n, INT_MAX);
        //      2   1   5   0   4   6
        //mn    +   2   1   1   0   0
        //mx    6   6   6   6   6   -
        
        for(int i=1;i<n;++i) mn[i] = min(mn[i-1], nums[i-1]);
        for(int i=n-2;i>-1;i--) mx[i] = max(mx[i+1], nums[i+1]);
        // 夾擠
        for(int i=1;i<n-1;++i){
            if(nums[i] > mn[i] && nums[i] < mx[i]) return true;
        }
        return false;      
    }
};
```
#### option 2 - reduce dp
```c++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //      2   1   5   0   4   6
        //m1    2   1   1   0   0   
        //m2    +   +   5   5   4   
        
        
        int m1 = INT_MAX, m2 = INT_MAX, n=nums.size();
        for(int i =0;i<n;++i){
            if(nums[i] <=m1) m1= nums[i];
            else if(nums[i]>m1 && nums[i]<= m2) m2 = nums[i];
            else return true;
        }
        return false;
    }
};
```
#### option 3 - Binary search
```c++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int piles = 0, n = nums.size();
        vector<int> top(n,0);
        for(int i=0;i<n;++i){
            int poker = nums[i];
            int l=0, r = piles;
            while(l<r){
                int mid = l + (r-l)/2;
                if(top[mid] > poker) r = mid ;
                else if(top[mid] == poker) r  = mid;
                else l = mid +1;
            }
            if(l==piles) piles++;
            top[l] = poker;
        }
        
        return piles>=3;
    }
};
```


## analysis


- TLE
    - time complexity `O(n^2)`
    - space complexity `O(n)`
- option 1
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 3 - Binary search
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
