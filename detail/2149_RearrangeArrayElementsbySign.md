---
title: 2149. Rearrange Array Elements by Sign
tags: 
    - Two Pointers
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/rearrange-array-elements-by-sign/submissions/)

## solution
#### option 1 - one pass
```c++
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int l = 0, r = 1, n= nums.size();
        vector<int> ret(n,0);
        for(int i=0;i<n;++i){
            if(nums[i]>0){
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
