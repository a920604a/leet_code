---
title: 2006. Count Number of Pairs With Absolute Difference K
tags:  
    - hash table
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/)


## solution
```c++
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp;
        int count = 0;
        for(int n:nums) mp[n]++;
        int i=0, n=nums.size();
        while(i<n){
            // cout<<nums[i]<<" ";
            if(mp.count(nums[i]+k)) count+= mp[nums[i]]*mp[nums[i]+k];
            
            while(i+1<n && nums[i]==nums[i+1]) i++;
            i++;
        
        }
        return count;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`