---
title: 2207. Maximize Number of Subsequences in a String
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/)

## solution


將`pattern[0]` 插入第一個`pattern[1]` 之前
或是
將`pattern[1]` 插入第一個`pattern[0]` 之前

```c++
class Solution {
public:
    bool isUnique(string str){
        int n = str.size();
        for(int i=0;i<n-1;++i){
            if(str[i]!=str[i+1]) return false;
        }
        return true;
    }
    long long countSubseq(string str, string pattern){
    
        long long count = 0;
        int i =0, n = str.size();
        if(str[0] == pattern[1]) str.insert(0,string(1, pattern[0]));
        else{
            while(i<n && str[i+1]!=pattern[1]) i++;
            str.insert(i, string(1,pattern[0]));
        }

        unordered_map<char,int> mp;
        for(char c:str) mp[c]++;
        for(int i=0;i<str.size() ; ++i){
            if(str[i] == pattern[0]) count+=mp[pattern[1]];
            else mp[pattern[1]]--;
        }
        return count;
    }
    long long countSubseqB(string str, string pattern){
        
        long long count = 0;
        int n = str.size(),  i = n-1;
        if(str[i] == pattern[0]) str.insert(i+1, string(1, pattern[1]));
        else{
            while(i>0 && str[i-1] !=pattern[0]) i--;
            str.insert(i+1, string(1, pattern[1]));
        }
        unordered_map<char,int> mp;
        for(char c:str) mp[c]++;
        for(int i=0;i<str.size() ; ++i){
            if(str[i] == pattern[0]) count+=mp[pattern[1]];
            else mp[pattern[1]]--;
        }
        return count;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        string str ;
        for(char c:text){
            if(c == pattern[0] || c==pattern[1]) str+=c;
        }
        // insert before  first pattern[1] 
        if(str.empty()) return 0;
        if(isUnique(str) ){
            if(pattern[0] != pattern[1]) return str.size();
            else{
                return (str.size()+1)*(str.size()-1+1)/2;
            }
        }
        return max(countSubseq(str, pattern), countSubseqB(str, pattern));
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`