---
title: 387. First Unique Character in a String
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/first-unique-character-in-a-string/)

## solution

```c++
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(char c:s) mp[c]++;
        int n = s.size();
        for(int i=0;i<n;++i){
            if(mp[s[i]] == 1) return i;
        }
        return -1;
    }
};
```
- vector
```c++
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26,0);
        for(char c:s) vec[c-'a']++;
        int n = s.size();
        for(int i=0;i<n;++i){
            if(vec[s[i] - 'a'] ==1) return i;
        }
        return -1;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)` 最多26字母
