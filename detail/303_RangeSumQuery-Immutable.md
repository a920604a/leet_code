---
title: 303. Range Sum Query - Immutable
tags:  
    - Prefix Sum
categories: leetcode
comments: false
---



## [problem](https://leetcode.com/problems/range-sum-query-immutable/)

## solution
- brute forces

```c++
class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        //  -2  0   3   -5  2   -1
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        // brute force
        int ret = 0;
        for(int i=left;i<=right;i++) ret+=nums[i];
        return ret;
    }
};

```

- prefix sum
```c++
class NumArray {
private:
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        //  -2  0   3   -5  2   -1
        //   0 -2  -2  1   -4  -2  -3
        int n = nums.size();
        preSum = vector<int>(n+1,0);
        for(int i=1;i<n+1;++i){
            preSum[i] = preSum[i-1] + nums[i-1];     
        }
    }
    int sumRange(int left, int right) {
        return preSum[right+1] - preSum[left];
    }
};
```
## analysis
- `sumRange` 函數 time complexity `O(1)`