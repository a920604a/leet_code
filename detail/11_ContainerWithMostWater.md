---
title: 11. Container With Most Water

tags:  
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/container-with-most-water/)
從陣列中，找出最大積水量

## solution
- 兩個索引分別從左往右，從右往左，直到兩索引相等時跳出迴圈，尋找最大積水量

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        int l =0,r = n-1;
        while(l<r){
            sum = max(sum, (r-l)*min(height[l], height[r]));
            if(height[l] < height[r]) l++;
            else r--;
        }
        return sum;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
