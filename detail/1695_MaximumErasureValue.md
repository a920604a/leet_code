---
title: 1695. Maximum Erasure Value
tags:  
    - hash table
    - sliding window
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-erasure-value/)

## solution
```c++
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // slide window
        int ret = 0;
        unordered_map<int,int> window, need;
        int l = 0, r = 0,n = nums.size(), len = 0, window_total =  0;
        while(r<n){
            int c = nums[r++];
            if(window[c]==0) len++;
            window[c]++;
            
            window_total+=c;
            while(window[c]>1){
                int d = nums[l++];
                window[d]--;
                if(window[d] == 0) len--;
                window_total-=d;
            }
            ret = max(ret, window_total);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`