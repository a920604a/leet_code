---
title: 645. Set Mismatch

tags:  
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/set-mismatch/)



## solution
- 遍歷陣列，並將元素在陣列中的正確位置(idx)
    - 未拜訪的元素，取倒數
    - 拜訪過的元素，則為重複出現的數字
- 再次遍歷陣列，找出正數，即為遺失的數字
```c++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int miss =0, dup = 0;
        //  1   2   2   4
        //  -1  -2  2   -4
        int n = nums.size();
        for(int i=0;i<n ; ++i){
            int idx = abs(nums[i])-1;
            if(nums[idx]>0) nums[idx]*=-1;
            else dup = abs(nums[i]);
        }
        for(int i=0;i<n;++i){
            if(nums[i]>0) miss = i+1;
        }
        return {dup, miss};
        
    }
};
```
## analyze
- time complexity `O(n)` 
- space complexity `O(1)`
