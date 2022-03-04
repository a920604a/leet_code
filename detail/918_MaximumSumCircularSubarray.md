---
title: 918. Maximum Sum Circular Subarray
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/maximum-sum-circular-subarray/)


## solution
```c++
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        //  5   -3  5   
        //  5   -3  2   
        // 尋找最大非循環子陣列 與 最大循環子陣列  = total sum - 最小和的子陣列
        
        int global_mx = INT_MIN, local = 0;
        local = 0;
        for(int n:nums){
            local = max(n, local+n);
            global_mx =  max(global_mx, local);
        }
        int global_mn = INT_MAX;
        local = 0;
        
        int total = 0;
        for(int n:nums){
            total+=n;
            local = min(n+local, n);
            global_mn = min(local, global_mn);
            
        }
        if( total == global_mn) return global_mx;
        return max(global_mx, total - global_mn);
    }
};

```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
