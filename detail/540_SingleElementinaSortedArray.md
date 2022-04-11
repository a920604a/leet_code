---
title: 540. Single Element in a Sorted Array
tags:  
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/single-element-in-a-sorted-array/)
## solution 
- cheat
```c++
int ret = 0;
for(int a:nums) ret^=a;
```

#### option 1 - *Binary Search
```c++
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        // 一定是奇數長度
        // 如果mid索引是偶數代表索引前面的數字應該都是兩兩一對，如果不是mid索引的值會與前一索引值相同，則落單的數必定在前面，反之相反。
        int l = 0, r = n-1;
        while(l<r){
            int mid = l +(r-l)/2;
            
            if (( mid % 2 == 1 && nums[mid] != nums[mid + 1]) || ( mid % 2 == 0 && nums[mid] == nums[mid + 1])) l = mid + 1;
            else r= mid;
            
            
        }
        return nums[l];
    }
};
```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`
