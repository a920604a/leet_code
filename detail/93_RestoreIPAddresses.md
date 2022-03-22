---
title: 93. Restore IP Addresses
tags:
    - backtracking
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/restore-ip-addresses/)

## solution
```c++
class Solution {
public:
    vector<string> ret;
    bool isValid(string s){
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int res = atoi(s.c_str());
        return res <= 255 && res >= 0;
    }
    
    void dfs(string s, int k, string path){
        if(k==0){
            if(s.empty()) ret.push_back(path);
            return;
        }
        for(int i=1;i<=3;++i){
            if(s.size() >= i  && isValid(s.substr(0,i) )){
                if(k==1) dfs(s.substr(i) , k-1, path+s.substr(0,i));
                else dfs(s.substr(i), k-1, path+s.substr(0,i)+'.');
                
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 4, "");
        return ret;
    }
};
```

