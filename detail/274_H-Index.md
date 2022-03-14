---
title: 274. H-Index
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/h-index/)


## solution
#### option 1
```c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n= citations.size();
        sort(citations.begin(), citations.end(), greater<>()) ;
        for(int i =0;i<n;++i){
            if(citations[i] <= i) return i;
            
        }
        return n;
    }
};
```

#### option 2 - binary search
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
- time complexity `O(nlogn)`
- space complexity `O(1)`
