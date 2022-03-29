---
title: 430. Flatten a Multilevel Doubly Linked List
tags:  
    - backtracking
categories: leetcode
---



## [problem](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

## solution
```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        stack<Node *> sta;
        Node *p = head;
        // iterative
        //flatten linked list
        while(p->next || p->child){
            if(p->child){
                sta.push(p->next);
                p->next = p->child;
                p->child = nullptr;
            }
            p=p->next;
        }
        while(!sta.empty()){
            Node *next = sta.top();
            sta.pop();
            p->next = next;
            while(p->next) p=p->next;
        }
        
        p=head;
        // build bi-direct connection
        while(p->next){
            p->next->prev = p;
            
            p=p->next;
        }
        p->next = nullptr;
        
        return head;
        
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`