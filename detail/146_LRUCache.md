---
title: 146. LRU Cache
tags:  
    - Linked List
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/lru-cache/)

## solution

#### option 1 
```c++
class Node{
public:
    int val, key ;
    Node *prev, * next;
    Node(int k,int v){
        key = k;
        val = v;
        prev= nullptr;
        next = nullptr;
    }
};
class DoubleLinkedList{
private:
    int size;
    Node *head, *tail;
public:
    
    DoubleLinkedList(){
        size = 0;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    // push back
    void push_back(Node *node){
        // Node *node = new Node(x);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }
    void push_front(Node *node){
        // Node *node = new Node(x);
        node->next= head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }
    // pop back
    void pop_back(){
        Node *node = tail->prev;
        // int ret = node->val;
        if(node == head) return ;
        tail->prev = node->prev;
        tail->prev->next = tail;
        size--;
        // return node->val;
    }
    Node* pop_front(){
        Node *node = head->next;
        if(node == tail) return nullptr;
        head->next = node->next;
        node->next->prev = head;
        size--;
        return node;
    }
    void remove(Node *node){
        Node *pre = node->prev;
        pre->next = node->next;
        pre->next->prev = pre;
        size--;
    }
    int getSize() {return size;}
};
class LRUCache {
private:
    //key 存key, value存 Node，可以由key 找到哪個Node，再去對cache做操作
    unordered_map<int,Node*> mp;
    DoubleLinkedList* cache;
    int cap;
public:
    
    LRUCache(int capacity) {
        cap = capacity;
        cache = new DoubleLinkedList();
    }
    
    // 將key 提升為最近使用
    void makeRecently(int key){
        Node *node = mp[key];
        cache->remove(node);
        cache->push_back(node);
        // mp[key] = node;
    }
    // 添加最近使用元素
    void addRecently(int key, int val){
        Node *node = new Node(key, val);
        cache->push_back(node);
        mp[key] = node;
    }
    // 刪除某一個key
    void deleteKey(int key){
        Node *node = mp[key];
        cache->remove(node);
        mp.erase(node->key);
    }
    // 刪除最久未使用的元素
    void removeLeastRecently(){
        Node *node = cache->pop_front();
        mp.erase(node->key);
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node = mp[key];
        makeRecently(key);
        return mp[key]->val;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            deleteKey(key);
            addRecently(key, value);
        }
        else{
            // 滿了
            if(cache->getSize() == cap || mp.size() == cap){
                removeLeastRecently();
            }
            addRecently(key , value);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

```

## analysis