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
        int l = 0,r =n-1, ret = 0;
        while(l<r){
            ret = max(ret, (r-l)*min(height[l], height[r]));
            height[l] < height[r] ? ++l : --r;
        }
        return ret;
    }
};
```

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            while (i < j && h == height[i]) ++i;
            while (i < j && h == height[j]) --j;
        }
        return res;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
