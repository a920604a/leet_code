---
title: 438. Find All Anagrams in a String
tags:  
    - hash table
    - Sliding Window
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## solution 
當 window、need 兩個窗口一樣時，且兩個索引等於p字串的長度，此時可以確保s[l:r] 子字串等於字串p

```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int l = 0, r=0, n=s.size(), valid = 0;
        unordered_map<char, int> need, window;
        for(char c:p) need[c]++;
        while(r<n){
            char c =s[r++];
            if(need.find(c)!=need.end()){
                window[c]++;
                if(window[c] == need[c]) valid++;
            }
            while(valid == need.size()){
                
                if(r-l == p.size()) ret.push_back(l);
                char d = s[l++];
                if(need.find(d)!=need.end()){
                    if(need[d] == window[d]) valid--;
                    window[d]--;
                }
            }
        }
        return ret;
    }
};
```
- 可以用固定大小的vector 代替hash table

```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> need(26,0), window(26,0), ret;
        int l =0, r = 0, m =p.size(), n=s.size();
        for(char c:p) need[c-'a']++;
        for(int i=0;i<n;++i){
            window[s[i]-'a']++;
            if(i>=m) window[s[i-m]-'a']--;
            if(need == window) ret.push_back(i-m+1);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`