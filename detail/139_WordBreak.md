---
title: 139. Word Break
tags:  
    - backtracking 
    - dp
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/word-break/)


## solution
#### option 1 - dfs + memo
```c++
class Solution {
public:
    unordered_set<string> words;
    vector<bool> memo;
    bool dfs(string s, int start){
        if(start == s.size()) return true;
        if(memo[start]) return memo[start];
        for(int i=start ; i<s.size() ; ++i){
            string  temp = s.substr(start,i-start +1);
        
            if(words.find(temp)!=words.end() && dfs(s, i+1)){
                return memo[start] = true;
            }
        }
        return false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        words = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo = vector<bool>(s.size(), false);
        return dfs(s, 0);
        
    }
};
```
#### option 2 - dp
```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        //  l   e   e   t   c   o   d   e
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=0;i<n+1;++i){
            for(int j=0;j<i;++j){
                if(dp[j] && words.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    // 因為 [o,j) 已經是單詞了，現在又確定[j,i) 也是單詞
                    break;
                }
            }
        }
        return dp.back();   
    }
};
```
#### option 3 - dp
```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        //  l   e   e   t   c   o   d   e
        int n = s.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        for(int i=0;i<n;++i){
            if(dp[i]!=-1){
                for(int j=i+1;j<=n;++j){
                    string temp = s.substr(i,j-i);
                    if(words.count(temp)) dp[j] = i;
                }
            }
        }
        return dp.back()!=-1;
    }
};
```
## analysis
- option 2 - dp
    - time complexity `O(n*dict.size())`
    - space complexity `O(n)`
