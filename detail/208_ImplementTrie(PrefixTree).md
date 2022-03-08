---
title: 208. Implement Trie (Prefix Tree)
tags:  
    - Trie
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/implement-trie-prefix-tree/)

## solution
先定義TrieNode 資料結構
Trie 只有葉子才會存資料，其餘只是指標



```c++
struct TrieNode{
    TrieNode* child[26];
    bool isWord;
    TrieNode():isWord(false){
        for(TrieNode* &c:child) c= nullptr;
    }
    
};
class Trie {
private:
    TrieNode * root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(char c:word){
            if(!cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
            cur = cur->child[c-'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(char c:word){
            if(!cur->child[c-'a']) return false;
            cur = cur->child[c-'a'];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(char c:prefix){
            if(!cur->child[c-'a']) return false;
            cur = cur->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
## analysis
search、insert、startWith operation
- time complexity `O(n)` , n = len(word)
