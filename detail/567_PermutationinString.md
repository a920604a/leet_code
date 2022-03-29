---
title: 567. Permutation in String

tags:  
    - Sliding Window
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/permutation-in-string/)


## solution
- 需要兩個hash table紀錄(因順序不重要)，一個紀錄需要match的字串，另一個hash table搭配雙指標(l, r)，並將l與r之間的字元放進，當兩個hash table一樣是，則代表如果 s1 的排列之一是 s2 的子字串

```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for(char c:s1) need[c]++;
        int l =0,r=0, n=s2.size(), valid = 0;
        while(r<n){
            char c = s2[r++];
            if(need.find(c)!=need.end()){
                window[c]++;
                if(window[c] == need[c]) valid++;
            }
            while(valid == need.size()){
                if(r-l == s1.size()) return true;
                char d = s2[l++];
                if(need.find(d)!=need.end()){
                    if(window[d] == need[d] ) valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};
```
- 可以用固定大小的vector 代替hash table

```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26,0), window(26,0);
        for(char c:s1) need[c-'a']++;
        int n =s1.size(), m = s2.size();
        for(int i=0;i<m;++i){
            window[s2[i]-'a']++;
            if(i>=n) window[s2[i-n]-'a']--;
            if(window==need) return true;
        }
        return false;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`