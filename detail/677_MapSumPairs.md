---
title: 677. Map Sum Pairs
tags:  
    - Trie
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/map-sum-pairs/)

## solution




```c++
class TrieNode{
public:
    bool isWord;
    int val;
    TrieNode* children[26];
    TrieNode(){
        val = 0;
        isWord = false;
        for(TrieNode * & child :children) child = nullptr;
    }
};
class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    TrieNode* put(TrieNode* node, string key, int val, int i){
        if(node == nullptr) node = new TrieNode();
        if(i == key.size()){
            node->val = val;
            return node;
        }
        char c = key[i];
        node->children[c-'a'] = put(node->children[c-'a'], key, val, i+1);
        return node;
    }
    void put(string key, int val){
        // iterative
        
        // TrieNode *p = root;
        // for(char c:key){
        //     if(!p->children[c-'a']) p->children[c-'a'] = new TrieNode();
        //     p=p->children[c-'a'];
        // }
        // p->val = val;
        // p->isWord = true;
        
        //recursive
        root = put(root, key, val, 0);
    }
    bool search(string word){
        TrieNode *p = root;
        for(char c:word){
            if(!p->children[c-'a']) return false;
            p=p->children[c-'a'];
        }
        return p->isWord;
    }
    
    // 從節點 node 開始搜索 key，如果存在返回對應節點，否則返回 null
    TrieNode* getNode(TrieNode *node, string key){
        TrieNode *p = node;
        // 從節點 node 開始搜索 key
        for (int i = 0; i < key.size(); i++) {
            if (!p ) {
                // 無往向下搜索
                return nullptr;
            }
            // 向下搜索
            char c = key[i];
            p = p->children[c-'a'];
        }
        return p;
    }
    // 搜索 key 對應的值，不存在則返回 null
    int get(string prefix){
        TrieNode * x = getNode(root, prefix);
        if (x == nullptr || x->val == 0) {
        // x 為空或 x 的 val 字段為空都说明 key 没有對應的值
            return 0;
        }
        return x->val;
    }
    // 搜尋所有前綴為prefix 所有鍵
    // keysWithPrefix("th") -> ["that", "the", "them"]
    vector<string> keysWithPrefix(string prefix){
        vector<string> ret;
        TrieNode * x = getNode(root, prefix);
        if(x==nullptr) return ret;
        // DFS 遍歷以 x 為根的這棵 Trie 樹
        traverse(x, prefix, ret);
        return ret;
        
    }
    // 遍歷以 node 節點為根的 Trie 樹，找到所有鍵
    void traverse(TrieNode *node, string path, vector<string> & ret){
        if(node == nullptr) return;
        
        if(node->val!=0) ret.push_back(path);
        for(char c = 'a';c<='z' ; ++c){
            path.push_back(c);
            traverse(node->children[c-'a'], path, ret);
            path.pop_back();
        }
        
        
    }
    // 遍歷函数，嘗試在「以 node 為根的 Trie 樹中」匹配 pattern[i..]
    void traverse(TrieNode * node, string path, string pattern, int i, vector<string> & ret){
        if(node==nullptr) return;
        
        if(i==pattern.size()){
            if(node->val!=0){
                ret.push_back(path);
            }
            return;
        }
        char c = pattern[i];
        if(c=='.'){
            for(char j = 'a' ;j<='z';++j){
                path.push_back(j);
                traverse(node->children[j-'a'], path,pattern, i+1, ret);
                path.pop_back();
            }
        }
        else{
            path.push_back(c);
            traverse(node->children[c-'a'], path,pattern, i+1, ret);
            path.pop_back();
        }
    }
    
};

class MapSum {
private:
    Trie *root;
public:
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        root->put(key, val);
    }
    
    int sum(string prefix) {
        vector<string> keys = root->keysWithPrefix(prefix);
        int ret = 0;
        for(string key:keys){
            ret+= root->get(key);
        }
        return ret;
        
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
```