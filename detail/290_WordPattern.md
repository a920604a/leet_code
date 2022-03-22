---
title: 290. Word Pattern
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/word-pattern/)
## solution

#### option 1
```c++
class Solution {
public:
    vector<string> split(string s){
        vector<string> ret;
        string cur ;
        for(char c:s){
            if(c==' '){
                ret.push_back(cur);
                cur.clear();
            }
            else cur+=c;
        }
        if(!cur.empty()) ret.push_back(cur);
        return ret;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> mpa;
        unordered_map <string,int> mpb;
        vector<string> str = split(s);
        if(str.size()!=pattern.size()) return false;
        for(int i=0;i<pattern.size() ; ++i){
            char c = pattern[i];
            if(mpa[c]!=mpb[str[i]]) return false;
            mpa[c] = i+1;
            mpb[str[i]] = i+1;
        }
        return true;
        
        
    }
};
```
#### option 2 
```c++
class Solution {
public:
    vector<string> split(string s){
        vector<string> ret;
        string cur ;
        for(char c:s){
            if(c==' '){
                ret.push_back(cur);
                cur.clear();
            }
            else cur+=c;
        }
        if(!cur.empty()) ret.push_back(cur);
        return ret;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        vector<string> str = split(s);
        if(str.size()!=pattern.size()) return false;
        for(int i=0;i<pattern.size() ; ++i){
            char c = pattern[i];
            if(mp.count(c)){
                if(mp[c] !=str[i]) return false;
            }
            // not exist in map key
            else {
                for(auto a:mp){
                    if(a.second == str[i]) return false;
                }
                mp[c] = str[i];
            }
        }
        return true;
        
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`