---
title: 205. Isomorphic Strings
tags:
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/isomorphic-strings/)

## solution

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mpa, mpb;
        int n = s.size(), m=t.size();
        if(m!=n) return false;
        for(int i=0;i<n;++i){
            if(mpa[s[i]]!=mpb[t[i]]) return false;
            mpa[s[i]] = i+1;
            mpb[t[i]] = i+1;
            
        }
        return true;
    }
};
```

## analysis
- time complexity `O(nlogn)`
- space complexity `O(n)`