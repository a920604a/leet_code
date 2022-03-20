---
title: 2206. Divide Array Into Equal Pairs
tags:
    - hash table
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/divide-array-into-equal-pairs/)

## solution
```c++
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int n:nums) freq[n]++;
        for(auto m:freq) {
            if(m.second%2==1) return false;
        }
        return true;
        
        
    }
};
```
```c++
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> vec(501,0);
        for(int n:nums) vec[n]++;
        for(int i=1;i<=500;++i){
            if(vec[i]%2==1) return false;
        }
        return true;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`
