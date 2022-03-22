---
title: 809. Expressive Words
tags:
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/expressive-words/)

## solution
```c++
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int n= s.size(), m = words.size(), count = 0;
        for(string word:words){
            int i = 0,j=0;
            for(;i<n;++i){
                if(j<word.size() && s[i] == word[j]) j++;
                else if(i>0 &&s[i] == s[i-1] && i+1 < n && s[i] ==s[i+1]) i++;
                else if(!(i>1 && s[i] == s[i-1] && s[i]== s[i-2])) break;
            }
            if(i == n && j == word.size()) count++;
        }
        return count;
    }
};
```
## analysis
- time complexity `O(nm)`
- space complexity `O(1)`


