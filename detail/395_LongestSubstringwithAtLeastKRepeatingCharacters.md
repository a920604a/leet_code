---
title: 395. Longest Substring with At Least K Repeating Characters
tags:
    - sliding window
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)

## solution
```c++
class Solution {
public:
    int longestSubstring(string s, int k) {
        // O(26n)
        int ret =  0 , n = s.size();
        // 子字串不同字母數介於 [1,26] 
        for (int cnt = 1; cnt <= 26; ++cnt) {
            // uniqueCnt 窗口有多少字母唯一
            int l = 0, r = 0, uniqueCnt = 0;
            unordered_map<char, int> window;
            while(r < n){
                bool valid = true;
                char c = s[r++];
                if(window[c] == 0) uniqueCnt++;
                window[c]++;
                // 不同字母數 超過cnt
                while(uniqueCnt > cnt){
                    char d = s[l++];
                    window[d]--;
                    if(window[d] == 0) uniqueCnt--;
                }
                
                // 檢查window 各個字母數量 是否少於 k 
                for(auto w:window){
                    if(w.second>0 && w.second<k) valid = false;
                }
                // 更新解答
                if(valid) ret = max(ret, r-l);
            }
        }
        return ret;
        
    }
};s
```


## analysis
- time complexity `O(26n)`
- space complexity `O(n)`
