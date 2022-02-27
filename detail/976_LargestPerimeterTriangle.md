---
title: 976. Largest Perimeter Triangle
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/largest-perimeter-triangle/)

## solution
```c++
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int perimeter = 0, n= nums.size();
        for(int i=n-2;i>=1;i--){
            if(nums[i]> nums[i+1] - nums[i-1]){
                perimeter = max(perimeter, nums[i]+ nums[i+1]+nums[i-1]);
            }
        }
        return perimeter;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`
