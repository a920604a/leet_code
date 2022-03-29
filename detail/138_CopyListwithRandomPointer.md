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
            ret->next = p->next;
        }
        
        for(Node *p = head;p;p=p->next){
            Node *random = p->random;
            mp[p]->random = mp[random];
        }
        return ans->next;
    }
};
```

#### option 2 
## analysis
- time complexity `O(n)`
- space complexity `O(n)`
