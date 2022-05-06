---
title: 1209. Remove All Adjacent Duplicates in String II
tags:  
    - stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)

## solution
- TLE
```c++
class Solution {
public:
    bool isValid(string s, int i, int k){
        if(i+k-1>=s.size()) return false;
        for(int j=i;j<i+k;++j){
            if(s[j]!=s[i]) return false;
        }
        return true;
    }
    bool islegal(stack<char> s, char c, int k){
        if(s.size()<k-1) return false;
        stack<char> temp = s;
        while(!temp.empty() && temp.top() == c){
            temp.pop();
            k--;
        }
        return k==1;
    }
    string removeDuplicates(string s, int k) {
        stack<char> sta;
        int n = s.size();
        for(int i=0;i<n;){
            if(isValid(s,i,k)){
                i+=k;
            }
            else{
                if(islegal(sta, s[i], k)){
                    while(!sta.empty() && sta.top() == s[i]){
                        sta.pop();
                    }
                }
                else sta.push(s[i]);
                i++;
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
#### option 1
```c++
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> sta;
        int n = s.size();
        for(char c:s){
            if(!sta.empty() && sta.top().first == c){
                auto p = sta.top();
                sta.pop();
                if(p.second == k-1) continue;
                else sta.push(make_pair(c,p.second+1));
            }
            else sta.push(make_pair(c,1));
            
        }
        string ret;
        while(!sta.empty()){
            ret.append(sta.top().second, sta.top().first);
            sta.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`
