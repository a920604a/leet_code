---
title: 2185. Counting Words With a Given Prefix
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/counting-words-with-a-given-prefix/)


## solution
```c++
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(), count = 0;
        for(string word:words){
            int i=0;
            for(char c:word){
                if(c!=pref[i]) break;
                else i++;
            }
            if(i==n) count++;
        }
        return count;
    }
};
```

## analysis
- time complexity `O(n+m)`
- space complexity `O(1)`

