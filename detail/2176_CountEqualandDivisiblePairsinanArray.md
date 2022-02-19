---
title: 2176. Count Equal and Divisible Pairs in an Array
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/)

## solution

```c++
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        // brute force => time complexity O(n^2)
        int n = nums.size(), count = 0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(nums[i]==nums[j] && (i*j)%k==0) count++;
            }
        }
        return count;
    }
};
```
## analysis
- time complexity `O(n)`
- speed complexity `O(1)`