---
title: 1047. Remove All Adjacent Duplicates In String
tags:  
    - stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)

## solution 
```c++
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sta;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(i+1< n && s[i] == s[i+1]) i++;
            else{
                if(!sta.empty() && sta.top()==s[i]) sta.pop();
                else sta.push(s[i]);
            }
        }
        string ret;
        while(!sta.empty()){
            ret+=sta.top();
            sta.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```
```c++
class Solution {
public:
    string removeDuplicates(string s) {
        string ret;
        stack<char> sta;
        for(char c:s){
            if(!sta.empty() && sta.top() == c) sta.pop();
            else sta.push(c);
        }
        while(!sta.empty()){
            ret+=sta.top();
            sta.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```
#### option 2 simplify option 1 without stack
```c++
class Solution {
public:
    string removeDuplicates(string s) {
        string ret;
        for(char c:s){
            if(!ret.empty() && ret.back() == c) ret.pop_back();
            else ret+=c;
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`
