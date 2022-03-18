---
title: 86. Partition List

tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/partition-list/)

## solution 
建立兩個指標分別收集大於等於x的節點與小於x的節點
```c++
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smaller = new ListNode(-1), *a = smaller , *bigger = new ListNode(-1), *b = bigger;
        ListNode *p = head;
        while(p){
            if(p->val >= x){
                b->next = p;
                b=b->next;
            }
            else{
                a->next = p;
                a=a->next;
            }
            p=p->next;
        }
        b->next = nullptr;
        a->next = bigger->next;
        return smaller->next;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`