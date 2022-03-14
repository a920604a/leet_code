---
title: 315. Count of Smaller Numbers After Self
tags:  
    - Binary Search
    - Segment Tree
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

## solution
```c++
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> t, ret(n,0);
        // insert sort + binary search
        
        for(int i=n-1;i>-1 ; --i){
            int target = nums[i];
            int l =0, r = t.size();
            // 要插入的數字為target 
            while(l<r){
                int mid = l + (r-l)/2;
                if(t[mid] < target)  l = mid +1;
                else r = mid ;
            }
            // r 說明有多少數字在後面且比 nums[i]大
            ret[i] = r;
            t.insert(t.begin()+r, nums[i]);
        }
        
        return ret;
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`