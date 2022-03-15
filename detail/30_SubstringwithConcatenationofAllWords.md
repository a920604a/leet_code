---
title: 30 Substring with Concatenation of All Words
tags:  
    - hash table
    - sliding window
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)

## solution
```c++
class Solution {x
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if(s.empty() || words.empty()) return {};
        vector<int> ret;
        unordered_map<string,int> wordCnt;
        // words 中每個詞彙長度一致
        int n= words.size(), len = words[0].size();
        for(auto &word:words) wordCnt[word]++;
        // s.size() 需轉為int data type
        for(int i=0;i<=(int)s.size()-n*len ; ++i){
            unordered_map<string, int> strCnt;
            int j=0;
            for(j=0;j<n;++j){
                string t = s.substr(i+j*len, len);
                // 如果不在詞彙表裡就break
                if(!wordCnt.count(t)) break;
                strCnt[t]++;
                // 相同詞彙出現兩次以上
                if(strCnt[t]> wordCnt[t]) break;
            }
            // words 每個詞彙都有在以i為索引開頭的字串
            if(j==n) ret.push_back(i);
        }
        return ret;
    }
};
```
## analysis
- time complexity `O(nm)`
- space complexity `O(m)` m is words