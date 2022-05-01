---
title: 2255. Count Prefixes of a Given String
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/count-prefixes-of-a-given-string/)
## solution
```c++
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0 ;
        
        for(int i=0;i<s.size();++i){
            string temp = s.substr(0,i+1);
            for(const auto word:words){
                if(word == temp) count++;
            }
        }
        return count;
    }
};
```
## analysis
- time complexity `O(nm)`
- space complexity `O(n)`