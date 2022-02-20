---
title: 213. House Robber II
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/house-robber-ii/)


## solution 
一個只搶[1,n-1]，另一個只搶[0,n-2]，再取最大值

```c++
class Solution {
public:
    int rob(vector<int>& nums, int l, int r){
        if(r==l) return nums[l];
        int dp0 = nums[l], dp1 = max(nums[l],nums[l+1]);
        int ret = dp1;
        for(int i=l+2;i<=r;++i){
            ret = max(dp0+nums[i], dp1 );
            dp0 = dp1;
            dp1 = ret;
        }
        return ret;
    }
    int rob(vector<int>& nums) {
        // option 1 因為只會發生兩種情況。
        // 從第一家開始搶，就不能搶第 n-1
        // 從第二家開始搶，就可以一直搶下去
        int n = nums.size();
        if(n==1) return nums[0];
        int l = 0, r = n-1;
        return max(rob(nums, l+1, r), rob(nums, l,r-1));
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
