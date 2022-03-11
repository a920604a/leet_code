---
title: 318. Maximum Product of Word Lengths
tags:
    - Bit Manipulation
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/maximum-product-of-word-lengths/)


## solution

#### option 1 - brute force
```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<set<char>> wordSet(n);
        for(int i=0;i<n;++i){
            for(char c:words[i]) wordSet[i].insert(c);
        }int ret = 0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                bool f = true;
                for(char c:words[j]){
                    if(wordSet[i].count(c)){
                        f = false;
                        break;
                    }
                }
                if(f){
                    int len  = words[i].size() *words[j].size();
                    ret = max( len, ret);
                }
            }
        }
        return ret;
    }
};
```


## analysis
- time complexity `O(n^3)`
- space complexity `O(nm)`