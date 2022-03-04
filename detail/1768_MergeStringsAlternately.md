---
title: 1768. Merge Strings Alternately

categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/merge-strings-alternately/)


## solution
```c++
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int l=0, r = 0;
        string str ="";
        // merge
        while(l<n && r<m){
            str+=word1[l++];
            str+=word2[r++];
        }
        while(l<n) str+=word1[l++];
        while(r<m) str+=word2[r++];
        return str;
    }
};
```


## analysis
- time complexity `O(n+m)`
- space complexity `O(1)`