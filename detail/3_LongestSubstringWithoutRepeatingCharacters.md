---
title: 3. Longest Substring Without Repeating Characters

tags: 
    - hash table
    - Sliding Window
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/)


Given a string, find the length of the longest substring without repeating characters.


## solution

利用一個hash table 紀錄window中，出現個字元與其次數，然後不斷向右移動window，當，當window內出現某個字元出現大於一次，則開始從左邊收縮，直到滿足個字元都為一

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int l = 0,r = 0, n = s.size(), ret = 0;
        while(r<n){
            char c = s[r++];
            window[c]++;
            while(window[c]>1){
                char d = s[l++];
                window[d]--;
            }
            ret = max(ret, r-l);
        }
        return ret;
    }
};
```

- 可以用固定大小的vector 代替hash table

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> window(128,0);
        int l =0, r=0, ret = 0, n=s.size();
        while(r<n){
            char c = s[r++];
            window[c]++;
            while(window[c]>1){
                char d = s[l++];
                window[d]--;
            }
            ret = max(ret, r-l);
        }
        return ret;
    }
};

```

## analysis
- time complexity `O(n)`
- space complexity `O(1)` , 最多26 個英文字母