---
title: 1679. Max Number of K-Sum Pairs
tags:  
    - Two Pointers
    - hash 
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/max-number-of-k-sum-pairs/)

## solution
#### option 1 - Two Pointers
```c++
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l =0, r = nums.size()-1;
        int count = 0;
        while(l<r){
            if(nums[l]+nums[r] == k){
                count++;
                l++;
                r--;
            }
            else if(nums[l] +nums[r] < k) l++;
            else r--;
        }
        return count;
    }
};
```
#### option 2 - hash table
- Two pass
```c++
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int n:nums) mp[n]++;
        int count = 0;
        for(int n:nums){
            if(mp[k-n]>0 && mp[n]>0){
                if(k-n == n && mp[n]>1){
                    count++;
                    mp[k-n]--;
                    mp[n]--;    
                }
                else if(k-n!=n){
                    count++;
                    mp[k-n]--;
                    mp[n]--;    
                }
                
            }
        }
        return count;
    }
};
```
- One Pass
```c++
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        for(int n:nums){
            if(mp[k-n]>0){
                count++;
                mp[k-n]--;
            }
            else{
                mp[n]++;
            }
        }
        return count;
    }
};
```
## analysis
- option 1 
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(n)`
    - space complexity `O(n)`
