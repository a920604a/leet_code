---
title: 209. Minimum Size Subarray Sum
tags: 
    - Sliding window
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-size-subarray-sum/)


## solution

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window
        int window = 0;
        int n = nums.size();
        int l=0, r = 0;
        int len = INT_MAX;
        while(r<n){
            int last = nums[r++];
            
            window+=last;
            while(window>=target){
                len =min(len, r-l);
                
                int first = nums[l++];
                window-=first;             
            }
        }
        return len==INT_MAX?0:len;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`