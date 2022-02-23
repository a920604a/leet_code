---
title: nSum 問題
tags:
    - Two Pointers
categories: 
    - CS
    - Algorithm
comments: false
---


**排序、雙指針**


## 題目
- 15 3Sum (Medium)
- 16 3Sum Closest
- 18 4Sum (Medium)
- 454 4Sum (Medium)
- 923 3Sum With Multiplicity (Medium)

## 觀念

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    // 先对数组排序
    sort(nums.begin(), nums.end());
    // 左右指针
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int sum = nums[lo] + nums[hi];
        // 根据 sum 和 target 的比较，移动左右指针
        if (sum < target) {
            lo++;
        } else if (sum > target) {
            hi--;
        } else if (sum == target) {
            return {lo, hi};
        }
    }
    return {};
}
```


