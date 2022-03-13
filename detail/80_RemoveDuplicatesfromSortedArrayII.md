---
title: 80. Remove Duplicates from Sorted Array II
tags:  
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

## solution

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int slow = 0, fast = 1, count =1;
        while(fast<n){
            if(nums[fast] == nums[slow] && count==1){
                count ++;
                nums[++slow] = nums[fast];
                fast++;
            }
            else if(nums[fast] == nums[slow] && count==2)  fast++;
            else if(nums[fast]!=nums[slow]){
                nums[++slow] = nums[fast];
                count = 1;
                fast++;
            }
            
        }
        return slow+1;
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`