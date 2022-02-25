---
title: 211. Design Add and Search Words Data Structure
tags:  
    - Trie
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/design-add-and-search-words-data-structure/submissions/)

## solution


#### option 1 - Trie
```c++
class TrieNode{
public:
    bool isWord;
    TrieNode* children[26];
    TrieNode(){
        isWord = false;
        for(TrieNode *& child :children) child = nullptr;
    }
};
class Trie{
private:
    TrieNode *root ;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode * p =root;
        for(char c:word){
            if(!p->children[c-'a']) p->children[c-'a'] = new TrieNode();
            p=p->children[c-'a'];
        }
        p->isWord = true;
    }
    bool hasKeyWithPattern(string pattern){
        TrieNode *p = root;
        return hasKeyWithPattern(p, pattern,0);
    }
    bool hasKeyWithPattern(TrieNode* node, string pattern, int i){
        if(!node) return false;
        
        if(i==pattern.size()) return node->isWord;
        
        char c = pattern[i];
        if(c!='.') {
            
            if(!node->children[c-'a']) return false;
            else return hasKeyWithPattern(node->children[c-'a'], pattern, i+1);
        }
        
        // 嘗試所有可能
        for(int j=0;j<26;++j){
            if(hasKeyWithPattern(node->children[j], pattern, i+1)) return true;
        }   
        // 都沒匹配
        return false;
    }
    
};
class WordDictionary {
private:
    Trie *root;
public:
    WordDictionary() {
        
        root = new Trie();
    }
    
    void addWord(string word) {
        this->root->insert(word);
        
    }
    
    bool search(string word) {
        
        return  root->hasKeyWithPattern(word);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
#### option 2 - hash table

將`word.size()` 當作key，value 則為 相同長度的所有字串
```c++

class WordDictionary {
private:
    unordered_map<int , vector<string>> words;
    bool isEqual(string a , string b){
        
        if(a.size()!=b.size()) return false;
        int n = a.size();
        for(int i=0;i<n;++i){
            if(b[i] == '.') continue;
            if(a[i]!=b[i])  return false;
        }
        return true;
    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        words[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto w:words[word.size()]){
            if(isEqual(w, word)) return true;
        }
        return false;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
## analysis