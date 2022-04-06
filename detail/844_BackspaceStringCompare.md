---
title: 844. Backspace String Compare
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/backspace-string-compare/)


## solution

```c++
class Solution {
public:
    string process(string s){
        string ret ;
        for(char c:s){
            if(c=='#'){
                if(!ret.empty()) ret.pop_back();
            }
            else ret+=c;
        }
        return ret;
    }
    bool backspaceCompare(string s, string t) {
        string ret, ans;
        string a = process(s), b = process(t);
        return a==b;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`