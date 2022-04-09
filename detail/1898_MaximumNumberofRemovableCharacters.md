---
title: 1898. Maximum Number of Removable Characters
tags:  
    - Binary Search
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/maximum-number-of-removable-characters/)
## solution 
- native , TLE
```c++
class Solution {
public:
    bool isSubseq(string s, string p){
        int n = s.size(), m=p.size();
        if(m>n) return false;
        int j = 0;
        for(int i=0;i<n;++i){
            if(p[j] == s[i]) j++;
        }
        return j==m;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        // native
        int ret = 0 , n = removable.size();
        for(int i=0;i<n;++i){
            s[removable[i]] = '#';
            if(isSubseq(s,p)) ret= i+1;
            else break;
        }
        return ret;
    }
};
```

#### option 1
```c++
class Solution {
public:
    bool isSubseq(string s, string p){
        int n = s.size(), m=p.size();
        if(m>n) return false;
        int j = 0;
        for(int i=0;i<n;++i){
            if(p[j] == s[i]) j++;
        }
        return j==m;
    }
    bool helper(string s, string p, vector<int> & removable, int mid){
        for(int i=0;i<=mid;++i){
            s[removable[i]] = ' ';
        }
        return isSubseq(s,p);
        
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l =0 , r = removable.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(helper(s, p, removable, mid) ) l = mid+1;
            else r = mid;
        }
        return l;
    }
};
```
## analysis
- time complexity `O(logn)`
- space complexity `O(1)`