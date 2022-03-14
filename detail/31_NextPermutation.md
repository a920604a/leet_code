---
title: 31. Next Permutation
tags:  
    - math
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/next-permutation/)

## [solution](https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order)
```

// 給定陣列如果是 降序，說明是全排列的最後一種情況，下一個排序則是初始排序
//  1   2   7   4   3   1
//  1   3   1   2   4   7 下一排列
//  step 1. 從右往左看，數字逐漸變大，直到2時才變小，
//  step 2. 然後在從右往前找第一個比 2 大的數字，是3
//  step 3. 將 2 3 交換，
//  step 4. 把3後面的數字反轉，讓其保持升序
```
```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 先從右往左找到，非遞增的位置
        int n = nums.size();
        int j = n-1;
        while(j>0 && nums[j-1] >= nums[j] ) j--;
        if(j==0){
            sort(nums.begin(),nums.end());
            return;
        }
        int pivot=j-1;
        int bigger = n-1;
        while(bigger > pivot && nums[bigger] <= nums[pivot]) bigger--;
        swap(nums[pivot], nums[bigger]);
        reverse(nums.begin()+pivot+1, nums.end());
        
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(1)`