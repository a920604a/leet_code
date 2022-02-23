---
title: 383. Ransom Note
tags:  
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/ransom-note/)

## solution

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size(), m = magazine.size();
        if(n>m) return false;
        vector<int> vec(26,0);
        for(char c:magazine) vec[c-'a']++;
        for(char c:ransomNote){
            vec[c-'a']--;
            if(vec[c-'a']<0) return false;
        }
        return true;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`