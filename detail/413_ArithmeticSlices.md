---
title: 413. Arithmetic Slices
tags:  
    - dp
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/arithmetic-slices/)


## solution
```c++
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        //  1   2   3   4
        //  0   0   1   3
        
        //  1   3   5   7   9   
        //  0   0   1   3   6 
        
        //  1   2   3   8   9   10
        //  0   0   1   0   0   1
        
    
        // sort(nums.begin(), nums.end());
        int n = nums.size(), ret = 0;
        vector<int> dp(n,0);
        // 從第三個元素開始
        for(int i=2;i<n;++i){
            int diff = nums[i-1] - nums[i-2];
            if(diff == nums[i] - nums[i-1]){
                dp[i] = dp[i-1]+1;
            }
            ret+=dp[i];
        }
        return ret;
        
    }
};
```