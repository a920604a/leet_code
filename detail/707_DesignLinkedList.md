---
title: 707. Design Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/design-linked-list/)
## solution 
#### option 1 - Linked List
- be carefull edge case
```c++
struct Node{
    int val ;
    Node *next;
    Node(int val){
        this->val = val;
        this->next= nullptr;
    }
};
class MyLinkedList {
private:
    int size;
    Node *head;
public:
    MyLinkedList() {
        size = 0;
        head = new Node(-1);
    }
    
    int get(int index) {
        if(index > size-1) return -1;
        Node *p = head->next;
        while(index--)p=p->next;
        return p->val;
    }
    
    void addAtHead(int val) {
        size++;
        Node *node = new Node(val);
        Node *post = head->next;
        node->next = post;
        head->next = node;
    }
    
    void addAtTail(int val) {
        size++;
        Node * p= head->next;
        // size == 0
        if(!p){
            head->next = new Node(val);
        }
        else{
            while(p->next) p=p->next;
            p->next = new Node(val);
        }   
    }
    void addAtIndex(int index, int val) {
        // be careful, index == size-1, equal append()
        if(index > size) return;
        size++;
        Node *node = new Node(val);   
        Node *p = head->next, *pre = head;
        while(index--) {
            pre = p;
            p=p->next;
        }
        pre->next = node;
        node->next = p;
    }
    
    void deleteAtIndex(int index) {
        if(index > size-1) return;
        size--;
        Node *p = head->next, *pre = head;
        while(index--) {
            pre = p;
            p=p->next;
        }
        pre->next= p->next;
    }
};
```
##### add tail pointer
```c++
class Node{
public:
    int val;
    Node *next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};
class MyLinkedList {
private:
    Node *head, *tail;
    int size ;
public:
    MyLinkedList() {
        size = 0;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
    }
    
    int get(int index) {
        if(index > size-1) return -1;
        Node * p = head->next;
        while(index--) p=p->next;
        return p->val;
    }
    
    void addAtHead(int val) {
        size++;
        Node *post = head->next;
        Node * node = new Node(val);
        head->next = node;
        node->next = post;
    }
    
    void addAtTail(int val) {
        size++;
        Node * p = head->next;
        Node * node = new Node(val);
        // size ==0
        if(p==tail){
            head->next = node;
            node->next = tail;
        }
        else{
            while(p->next!=tail) p=p->next;
            p->next = node;
            node->next = tail;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index > size ) return;
        size++;
        Node *p = head->next, *pre = head;
        while(index--) {
            pre = p;
            p=p->next;
        }
        Node * node = new Node(val);
        pre->next = node;
        node->next = p;
        
    }
    
    void deleteAtIndex(int index) {
        if(index > size -1) return;
        size--;
        Node *p = head->next, *pre = head;
        while(index--) {
            pre = p;
            p=p->next;
        }
        pre->next = p->next;
        
    }
};

```
#### option 2 - Double Linked List
```c++
class Node{
public:
    int val;
    Node *next, *prev;
    Node(int val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class MyLinkedList {
private:
    Node *head, *tail;
    int size ;
public:
    MyLinkedList() {
        size = 0;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        if(index > size-1) return -1;
        Node * p = head->next;
        while(index--) p=p->next;
        return p->val;
    }
    
    void addAtHead(int val) {
        size++;
        Node *post = head->next;
        Node * node = new Node(val);
        node->prev = head;
        node->next = post;
        head->next = node;
        post->prev = node;
    }
    
    void addAtTail(int val) {
        size++;
        Node * p = head->next;
        Node * node = new Node(val);
        // head->next == prev;
        if(p==tail){
            node->next = tail;
            tail->prev = node;
            node->prev = head;
            head->next = node;
        }
        else{
            while(p->next!=tail) p=p->next;
            p->next = node;
            node->prev = p;
            node->next = tail;
            tail->prev = node;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index > size ) return;
        size++;
        Node *p = head->next, *pre = head;
        while(index--) {
            pre = p;
            p=p->next;
        }
        Node * node = new Node(val);
        pre->next = node;
        node->prev = pre;
        node->next = p;
        p->prev = node;
    }
    
    void deleteAtIndex(int index) {
        if(index > size -1) return;
        size--;
        Node *p = head->next, *pre = head;
        while(index--) {
            pre = p;
            p=p->next;
        }
        pre->next = p->next;
        pre->next->prev = pre;
    }
};
```
