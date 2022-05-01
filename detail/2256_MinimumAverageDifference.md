---
title: 2256. Minimum Average Difference
tags:
    - Prefix Sum
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/minimum-average-difference/)
## solution
```c++
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        long total = 0, ret = INT_MAX , ans = -1;
        for(const auto n:nums) total+=n;
        long lsum = 0, rsum = total;
        for(int i=0;i<n;++i){
            lsum+=nums[i];
            rsum-=nums[i];
            int lv , rv ;
            lv = lsum/(i+1);
            if(i==n-1) rv = 0.0;
            else rv = rsum/(n-i-1);
            if(abs(lv-rv) < ret){
                ret = abs(lv-rv);
                ans = i;
            }
            
        }
        return ans;
    }
};
```
## analysis

- time complexity `O(n)`
- space complexity `O(1)`