---
title: 41. First Missing Positive

tags:  
    - 
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)


## solution
#### option 1 - cheat
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    
        sort(nums.begin(),nums.end());
        int cur = 1;
        for(int n:nums){
            if(n==cur) cur++;

        }
        return cur;
    }
};
```

#### option 2 - histogram or hash table
```c++
```

#### option 3 - swap

不斷地交換

## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(1)`
- option 2 
    - time complexity `O(n)`
    - space complexity `O(n)`
- option 3 
    - time complexity `O(n)`
    - space complexity `O(1)`