---
title: 26. Remove Duplicates from Sorted Array
tags:  
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)


## solution
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0, n= nums.size();
        while(fast<n){
            // 維護nums[0...slow] 無重複就好
            if(nums[slow] != nums[fast]) nums[++slow] = nums[fast];
            fast++;
        }
        return slow+1;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`