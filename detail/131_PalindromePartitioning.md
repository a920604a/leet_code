---
title: 131. Palindrome Partitioning
tags:  
    - dp
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/palindrome-partitioning/)

## solution 
#### option 1 - dfs
```c++
class Solution {
public:
    vector<vector<string>> ret;
    bool isPalindrome(string s, int l, int r){
        while(l<r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    void dfs(string s, int start, vector<string> & path){
        if(start==s.size()){
            ret.push_back(path);
        }
        
        for(int i=start;i<s.size() ; ++i){
            if(!isPalindrome(s, start,i)) continue;
            path.push_back(s.substr(start, i-start+1));
            dfs(s,i+1, path);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, 0, path);
        return ret;
        
        
    }
};
```
#### option 2 - dp
