---
title: 2215. Find the Difference of Two Arrays
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-the-difference-of-two-arrays/)
## solution
```c++
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<set<int>> ret(2);
        unordered_set<int> s, intersection;
        for(int n:nums1) s.insert(n);
        for(int n:nums2){
            if(s.count(n)) intersection.insert(n);
        }
        for(int n:nums1){
            if(!intersection.count(n)) ret[0].insert(n);
        }
        for(int n:nums2){
            if(!intersection.count(n)) ret[1].insert(n);
        }
        vector<vector<int>> ans(2);
        for(int i=0;i<2;++i){
            for(auto a:ret[i]) ans[i].push_back(a);
        }
        return ans;
    }
};
```
## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`
