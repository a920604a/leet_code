---
title: 409. Longest Palindrome
tags:
    - hash table
    - greedy
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-palindrome/)

## solution 
#### option 1 
```c++
class Solution {
public:
    int longestPalindrome(string s) {
        
        // 不用在意順序
        // 統計個字母出現次數 , 2n+1, 2n 都可以是回文
        
        vector<int> vec(128,0);
        for(char c:s) vec[c]++;
        int one = 0, ret = 0;
        for(int a:vec){
            if(a&1) one++;
            ret+=a/2*2;
        }
        if(one>0) ret++;
        return ret;
    }
};
```
#### option 2 - set
```c++
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int ret = 0;
        for(char c:s){
            if(st.count(c)){
                st.erase(c);
                ret+=2;
            }
            else st.insert(c);
        }
        if(st.size()>=1) return ret+1;
        else return ret;
    }
};
```

## analysis
- option 1 
    - time complexity `O(n)`
    - space complexity `O(1)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`