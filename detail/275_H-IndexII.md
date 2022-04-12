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
        // given ascwnding order
        
        reverse(citations.begin(), citations.end());
        int n = citations.size();
        int l = 0, r = n-1;
        // 找出最小的索引其數值小於其索引
        //              -
        //  0   1   2   3   4   
        //  6   5   3   1   0
        
        
        //          -    
        //  0   1   2
        //  100 2   1
        while(l<=r){
            int mid = l +(r-l)/2;
            if(citations[mid] > mid) l = mid+1;
            else r= mid-1;
        }
        return l;
    }
};
```

#### option 1
```c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // given ascending order
        int n = citations.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l +(r-l)/2;
            if (citations[mid] == n - mid) return n - mid;
            else if (citations[mid] > n - mid) r = mid - 1;
            else l = mid + 1;
        }
        return n-l;
    }
};
```
## analysis
- time complexity `O(n)` `O(logn)`
- space complexity `O(1)`