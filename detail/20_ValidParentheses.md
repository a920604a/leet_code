---
title: 20. Valid Parentheses

tags:  
    - stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/valid-parentheses/)


## solution 

經典題目，利用stack 將`(` `[` `{` push 進去，如果不是左半部括號，則檢查stack 頂部是否為相對應的右半部括號，如果不是`return false`，如果是pop，並繼續遍歷`string`


```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(char c:s){
            if(c=='(' || c=='[' || c=='{') sta.push(c);
            else{
                if(sta.empty()) return false;
                else if(c==')' && sta.top() == '(') sta.pop();
                else if(c==']' && sta.top() == '[') sta.pop();
                else if(c=='}' && sta.top() == '{') sta.pop();
                else return false;
            }
        }
        return sta.empty();
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`
