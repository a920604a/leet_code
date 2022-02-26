---
title: 905. Sort Array By Parity
tags: 
    - Two Pointers
    - sorting
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/sort-array-by-parity/)

## solution
#### option 1 - two pass
```c++
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        int j = n-1;
        while(j>-1){
            if(nums[j]%2==0) ret.push_back(nums[j]); 
            j--;
        }
        j = 0;
        while(j < n){
            if(nums[j]&1) ret.push_back(nums[j]);
            j++;
        }
        return ret;
    }
};
```

#### option 2 - one pass 
```c++
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n,0);
        int l=0, r = n-1;
        for(int i=0;i<n;++i){
            if(nums[i]%2==0) ret[l++] = nums[i];
            else ret[r--] = nums[i];
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
