---
title: 153. Find Minimum in Rotated Sorted Array

tags:  
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

各元素唯一
## solution
#### option 1 - Binary Search

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            // 代表最小值會在 [mid+1, r] 之間
            if(nums[mid] > nums[r]) l = mid+1;
            // 右半部遞增，下次搜尋區間 [l, mid]
            else if(nums[mid] < nums[r]) r = mid;
        }
        return nums[l];
        
    }
};
```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`