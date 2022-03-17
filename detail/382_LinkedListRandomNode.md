---
title: 382. Linked List Random Node
tags:
    - Randomized
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/linked-list-random-node/)

## solution

#### option 1 - cheat , container to store
```c++
class Solution {
private:
    vector<int> vec;
    int size ;
public:
    Solution(ListNode* head) {
        size = 0;
        ListNode *p;
        for(p=head;p;p=p->next) {vec.push_back(p->val);size++;}
    }
    
    int getRandom() {
        
        return vec[rand()%size];
    }
};
```

#### option 2 - algo

```c++
class Solution {
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int count = 1;
        ListNode *p = head;
        int ret = 0;
        while(p){
            if(rand()%count==0) ret = p->val;
            
            count++;
            p=p->next;
        }
        return ret;
    }
};
```