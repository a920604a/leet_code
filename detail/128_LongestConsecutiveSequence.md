---
title: 128. Longest Consecutive Sequence
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-consecutive-sequence/)

## solution
```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // hash table 紀錄數字與包含該數字的最長區間長度
        unordered_map<int,int> mp;
        int ret = 0;
        for(int n :nums){
            if(mp.find(n)!=mp.end()) continue;
            int l = (mp.count(n-1))?mp[n-1]:0;
            int r = (mp.count(n+1))?mp[n+1]:0;
            int sum = r+l+1;
            mp[n] = sum;
            mp[n-l] = sum;
            mp[n+r] = sum;
            ret = max(ret,sum);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`