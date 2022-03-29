---
title: 283. Move Zeroes
tags:  
    - Two Pointers
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/move-zeroes/)

## solution
```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int slow= -1, fast =0, n=nums.size();
        while(fast<n){
            if(nums[fast]!=val) nums[++slow] = nums[fast];
            fast++;
        }
        return slow+1;
    }
    void moveZeroes(vector<int>& nums) {
        
        int pos = removeElement(nums,0);
        for(int i=pos;i<nums.size();++i) nums[i] = 0;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`