---
title: 140. Word Break II
tags:  
    - backtracking 
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/word-break-ii/)
## solution

#### option 1 - dfs
```c++
class Solution {
public:
    vector<string> ret;
    unordered_set<string> words;
    bool dfs(string s, int start, string path){
        if(start == s.size()){
            path.pop_back();
            ret.push_back(path);
        }
        
        for(int i=start;i<s.size() ; ++i){
            string temp = s.substr(start, i-start+1);
            if(words.count(temp) && dfs(s, i+1, path+temp+' ') ) return true;
        }
        return false;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        words = unordered_set<string>(wordDict.begin(), wordDict.end());
        string path;
        dfs(s, 0, path);
        return ret;
    }
};
```
#### option 2 - memo
```c++
class Solution {
public:
    unordered_map<string, vector<string>> memo;
    vector<string> wordBreak(string s, unordered_set<string> words){
        if(s.empty()) return {""};
        if(memo.count(s)) return memo[s];
        vector<string> ret;
        for(auto word:words){
            if(s.substr(0, word.size()) != word) continue;
            vector<string> temp = wordBreak(s.substr(word.size()), words);
            for(string str:temp){
                ret.push_back(word+(str.empty()?"":" ") +str);
            }
        }
        
        return memo[s] = ret;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return wordBreak(s, words);
        
    }
};
```
## analysis
