---
title: 127. Word Ladder
tags:  
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/word-ladder/)

## solution

#### option 1 
```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(!words.count(endWord)) return 0;
        int depth = 1;
        queue<string> q({beginWord});
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                string p = q.front();
                q.pop();
                if(p == endWord) return depth;
                
                int len = p.size();
                for(int j=0;j<len;++j){
                    string temp = p;
                    for(char c = 'a' ;c<='z';++c){
                        string t = temp;
                        t[j] = c;
                        if(!visited.count(t) && words.count(t)){
                            q.push(t);
                            visited.insert(t);
                        }
                    }
                }
            }
            depth++;
        }
        return 0;
        
    }
};
```

> find() 代替count 會更快

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end()) return 0;
        int depth = 1;
        queue<string> q({beginWord});
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                string p = q.front();
                q.pop();
                if(p == endWord) return depth;
                int len = p.size();
                for(int j=0;j<len;++j){
                    string temp = p;
                    for(char c = 'a' ;c<='z';++c){
                        temp[j] = c;
                        if(visited.find(temp)==visited.end() && words.find(temp)!=words.end()){
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            depth++;
        }
        return 0;
        
    }
};
```
## analysis

- time complexity `O(nm)`
- space complexity `O()`