---
title: Trie
tags:  
    - Trie
categories: 
    - CS
    - Data Structure
comments: false
---


## 題目
- 208 Implement Trie (Prefix Tree) (Medium)
- 1804 Implement Trie II (Prefix Tree) (Medium, Premium)
- 648 Replace Words (Medium)
- 211 Design Add and Search Words Data Structure (Medium)
- 677 Map Sum Pairs (Medium)

[補充]
- 139 Word Break (Medium)
- 140 Word Break II (Hard)
- 212 Word Search II (Hard)
- 336 Palindrome Pairs (Hard)


## 觀念

- Binary Tree 
```c++
class TreeNode{
    int val;
    TreeNode left, right;
};
```
- N-ary Tree 
```c++
class TreeNode{
    int val;
    TreeNode[] children;
};
```

- TrieNode
```c++
class TrieNode<V>{
    V val = null;
    TrieNode<V> [] children = new TrieNode[256];
}
```

## Implement Trie (Prefix Tree)

```c++
class TrieNode{
public:
    TrieNode * children[26];
    bool isWord;
    TrieNode(){
        this->isWord = false;
        for(TrieNode * & child:this->children) child = nullptr;
    }
};
class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void put(string word) {
        TrieNode *p = root;
        for(char c:word){
            if(p->children[c-'a'] == nullptr) p->children[c-'a'] = new TrieNode();
            p=p->children[c-'a'];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *p = root;
        for(char c:word){
            if(p->children[c-'a'] == nullptr)  return false;
            p=p->children[c-'a'];
        }
        return p->isWord;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(char c:prefix){
            if(p->children[c-'a'] == nullptr) return false;
            p=p->children[c-'a'];
        }
        return true;
        
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

```
## implement Trie ans API
```c++

class TrieNode{
public:
    TrieNode * children[26];
    bool isWord;
    TrieNode(){
        this->isWord = false;
        for(TrieNode * & child:this->children) child = nullptr;
    }
};
class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p = root;
        for(char c:word){
            if(p->children[c-'a'] == nullptr) p->children[c-'a'] = new TrieNode();
            p=p->children[c-'a'];
        }
        p->isWord = true;
    }
    // 判斷是否有word 在trie
    bool search(string word) {
        TrieNode *p = root;
        for(char c:word){
            if(p->children[c-'a'] == nullptr)  return false;
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
    
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(char c:prefix){
            if(p->children[c-'a'] == nullptr) return false;
            p=p->children[c-'a'];
        }
        return true;
        
    }
    // 在所有键中寻找 word 的最短前缀
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

    // 通配符 . 匹配任意字符，判断是否存在匹配的键
    // hasKeyWithPattern(".ip") -> true
    // hasKeyWithPattern(".i") -> false
    // 判断是和否存在前缀为 prefix 的键
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


```
## Replace Words

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
    // bool startsWith(string word){
    //     TrieNode *p = root;
    //     for(char c:word){
    //         if(!p->children[c-'a']) return false;
    //         p=p->children[c-'a'];
    //     }
    //     return true;
    // }
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

## Design Add and Search Words Data Structure 通配符

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