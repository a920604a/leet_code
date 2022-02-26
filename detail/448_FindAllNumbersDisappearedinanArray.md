---
title: 448. Find All Numbers Disappeared in an Array
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

## solution
```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        // 4,3,2,7,8,2,3,1
        // 1,2,2,2,3,4,7,8
        // -4, -3, -2, -7, 8, 2, -3, -1
        vector<int> ret;
        for(int i=0;i<n;++i){
            int idx = abs(nums[i])-1;
            if(nums[idx]>0) nums[idx] *= (-1);
        }
        for(int i=0;i<n;++i){
            if(nums[i]>0) ret.push_back(i+1);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`