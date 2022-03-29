---
title: 138. Copy List with Random Pointer
tags:
    - Hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/copy-list-with-random-pointer/)


## solution
遍歷各節點，用hash table 維護每個節點與其對應新的節點
再次遍歷個節點，並賦予隨機節點

#### option 1
```c++
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *ret = new Node(-1), *ans = ret;
        for(Node *p = head;p;p=p->next){
            ret->next = new Node(p->val);
            ret = ret->next;
            mp[p] = ret;
        }
        
        for(Node *p = head;p;p=p->next){
            mp[p]->random = mp[p->random];
        }
        return ans->next;
    }
};
```

#### option 2 
將兩件列先合併，在賦予random
`cur->next->random = cur->random->next;`
在將兩串列拆開
```c++

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *cur = head;
        while(cur){
            Node *t = new Node(cur->val);
            t->next = cur->next;
            cur->next = t;
            cur = t->next;
        }
        cur = head;
        while(cur){
            if(cur->random){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        Node *ret = head->next;
        while(cur){
            Node *t = cur->next;
            cur->next = t->next;
            if(t->next) t->next = t->next->next;
            cur=cur->next;
        }
        return ret;
        
    }
};
```
## analysis
- option 1
    - time complexity `O(nlogn)`
    - space complexity `O(n)`
- option 2
    - time complexity `O(n)`
    - space complexity `O(1)`