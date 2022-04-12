---
title: 611. Valid Triangle Number
tags:  
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/valid-triangle-number/)

## solution 
```c++
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 遞增數列 a b c => 只需檢查a+b>c即可
        sort(nums.begin(),nums.end());
        int ret= 0 ,n=nums.size();
        for(int i=0;i<n-2;++i){
            for(int j = i+1;j<n-1;j++){
                // 找到最後一個小於 nums[i] + nums[j]    
                int sum = nums[i] + nums[j];
                int l = j+1, r = n-1;
                while(l<=r){
                    int mid = l + (r-l)/2;
                    if(nums[mid] >= sum) r = mid -1;
                    else l = mid+1;
                }
                ret+=r-j;   
            }
        }
        return ret;
        
    }
};
```

## analysis
- time complexity `O(n^2logn)`
- space complexity `O(1)`