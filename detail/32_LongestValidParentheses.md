---
title: 32. Longest Valid Parentheses
tags:  
    - stack
    - dp
    - Two pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-valid-parentheses/)

## solution 

#### option 1
```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        int start = 0, ret= 0;
        for(int i=0;i<s.size();++i){
            char c= s[i];
            if(c=='('){
                sta.push(i);
            }
            else{
            
                if(sta.empty()) start = i+1;
                else{
                    sta.pop();
                    if(sta.empty()) ret = max(i-start+1, ret);
                    else ret = max(ret, i- sta.top());
                        
                }
                
            }
        }
        return ret;
    }
};
```
#### option 2 - dp
#### option 3 - Two Pointers , reduce dp