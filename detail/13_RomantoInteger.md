---
title: 13. Roman to Integer
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/roman-to-integer/)
## solution
```c++
class Solution {
public:
    unordered_map<char ,int> mp = {
        {'I',1},{'V',5},{'X',10},{'L', 50},{'C', 100},{'D', 500},{'M',1000}
    };
    int romanToInt(string s) {
        int ret = 0;
        for(int i= 0 ;i<s.size() ; ++i){
            ret+=mp[s[i]];
            int sub =0 ;
            int j = i-1;
            while(j > -1 && mp[s[i]] > mp[s[j]]) {
                sub+=mp[s[j]];
                j--;
            }
            ret-= 2*sub;
        }
        return ret;
    }
};
```
```c++
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict= {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ret = dict[s[0]];
        for(int i =1;i<s.size();++i){
            if(dict[s[i-1]] <dict[s[i]])  ret +=  (dict[s[i]]-2*dict[s[i-1]]);
            else if(dict[i-1] >= dict[i]) ret +=dict[s[i]];
        }
        
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
