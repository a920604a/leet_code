---
title: 81. Search in Rotated Sorted Array II

tags:  
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)


## solution
如果最左邊或最右邊與中間一樣(因為可能重複數值)，就往將右索引往左移動一個

```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(nums[mid] == target) return true;
            // 右半部遞增
            else if(nums[mid] < nums[r]){
                if(nums[mid] < target && target<= nums[r]) l = mid+1;
                else r = mid-1;
            }
            else if(nums[mid] > nums[r]){
                if(nums[l] <= target && target < nums[mid]) r = mid-1;
                else l = mid+1;
            }
            else r--;
        }
        return false;
    }
};
```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`