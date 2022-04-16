---
title: 2239. Find Closest Number to Zero
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-closest-number-to-zero/)
## solution
```c++
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ret = nums[0];
        for(int n:nums){
            if(abs(n) <= abs(ret) ) {
                if(abs(n)==abs(ret) && n>0) ret= n;
                // else if(abs(n) == abs(ret)) continue;
                else if(abs(n) < abs(ret)) ret = n;
            }
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`