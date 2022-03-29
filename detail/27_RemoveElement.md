---
title: 27. Remove Element
tags:  
    - Two Pointers
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/remove-element/)

## solution

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0, n = nums.size();
        while(fast<n){
            if(nums[fast] !=val ) nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`