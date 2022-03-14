---
title: 324. Wiggle Sort II
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/wiggle-sort-ii/)



## solution

```c++
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = (n-1)/2,  r = n-1;
        vector<int> ret(n,0);
        for(int i=0;i<n;++i){
            if(i%2==0) ret[i] = nums[l--];
            else ret[i] = nums[r--];
        }
        nums = ret;
    }
};
```

## analysis

- time complexity `O(nlogn)`
- space complexity `O(n)`