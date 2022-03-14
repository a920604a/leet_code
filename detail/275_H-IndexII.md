---
title: 275. H-Index II
tags:
    - Binary Search
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/h-index-ii/)


## solution
```c++

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n= citations.size();
        sort(citations.begin(), citations.end(), greater<>()) ;
        int l = 0, r= n-1;
        while(l<=r){
            
            int mid = l + (r-l)/2;
            if(citations[mid] > mid ) l = mid+1;
            else r = mid - 1;
        }
        return l;
        
    }
};

```

## analysis
- time complexity `O(logn)`
- space complexity `O(1)`