---
title: 22. Generate Parentheses
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/generate-parentheses/)

## solution
#### option 1 - dfs
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

#### option 2
```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        vector<int> diff;
        ret.push_back("");
        diff.push_back(0);
        for(int i=0;i<n*2;++i){
            vector<string> temp1;
            vector<int> temp2;
            for(int j=0;j<ret.size() ;++j){
                string s = ret[j];
                int k = diff[j];
                
                if(i<2*n-1){
                    temp1.push_back(s+"(");
                    temp2.push_back(k+1);
                }
                
                if(k>0 && i<2*n-1 || k==1 && i==2*n-1){
                    temp1.push_back(s+")");
                    temp2.push_back(k-1);
                }
            }
            ret= temp1;
            diff = temp2;
        }
        return ret;
    }
};
```