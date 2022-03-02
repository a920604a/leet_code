---
title: 22. Generate Parentheses
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/generate-parentheses/)

## solution
```c++
class Solution {
public:
    vector<string> ret;
    void backtracking(int l, int r, string  path){
        // 目前為止右括號用的比左括號多
        if(l>r) return ;
        if(l==0 && r==0){
            ret.push_back(path);
            return;
        }
        if(l< 0 || r<0 ) return ;
        backtracking(l-1, r,path+'(' );
        backtracking(l, r-1, path+')');
    }
    vector<string> generateParenthesis(int n) {
        string path;
        backtracking(n,n, path);
        return ret;
        
    }
};
```