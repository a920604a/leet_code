---
title: 648. Replace Words
tags:  
    - Trie
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/replace-words/)

## solution
```c++
class TrieNode{
public:
    TrieNode *children[26];
    bool isWord;
    TrieNode (){
        for(TrieNode* &child:this->children) child = nullptr;
        this->isWord = false;
    }
    
};
class Trie{
private:
    TrieNode *root;
public:
    Trie (){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode *p = root;
        for(char c:word){
            if(!p->children[c-'a']) p->children[c-'a'] = new TrieNode();
            p=p->children[c-'a'];
        }
        p->isWord= true;
    }
    bool search(string word){
        TrieNode *p = root;
        for(char c:word){
            if(!p->children[c-'a']) return false;
            p=p->children[c-'a'];
        }
        return p->isWord;
    }
    bool startsWith(string word){
        TrieNode *p = root;
        for(char c:word){
            if(!p->children[c-'a']) return false;
            p=p->children[c-'a'];
        }
        return true;
    }
    string shortestPrefixOf(string word){
        string ret;
        TrieNode *p = root;
        for(int i=0;i<word.size() ; ++i){
            char c = word[i];
            if(p->children[c-'a']) {
                ret+=string(1,c);
                p=p->children[c-'a'];
            }
            else return "";
            
            if(p->isWord) return ret;
        }
        return "";
    }
};


class Solution {
public:
    vector<string> split(string sentence){
        int j=0;
        int n= sentence.size();
        vector<string> words ;
        while(j<n && sentence[j]==' ') j++;
        int i;
        for(i=j;i<n;++i){
            if(sentence[i] ==' '){
                words.push_back(sentence.substr(j, i-j));
                j=i+1;
            }
        }
        words.push_back(sentence.substr(j, i-j));
        return words;
        
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        // 將dictionary 放入Trie  
        Trie *t = new Trie();
        for(string s:dictionary){
            t->insert(s);
        }
        vector<string> words = split(sentence);
        string ret ;
        
        int len = words.size();
        for(int i=0;i<len; ++i){
            string prefix = t->shortestPrefixOf(words[i]);
            if(!prefix.empty()) ret+=prefix;
            else ret+=words[i];
            if(i<len-1) ret+=' ';
        }
        return ret;
        
    }
};

```

