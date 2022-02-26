---
title: 922. Sort Array By Parity II
tags: 
    - Two Pointers
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sort-array-by-parity-ii/)

## solution

#### option 1 - one pass 
```c++
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size() ,  l = 0, r = 1;
        vector<int> ret(n,0);
        for(int i = 0;i<n;++i){
            if(nums[i]%2==0){
                ret[l] = nums[i];
                l+=2;
            }
            else{
                ret[r] = nums[i];
                r+=2;
            }
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
