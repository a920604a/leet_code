---
title: 328. Odd Even Linked List
tags:  
    - Linked List
    - Two Pointers
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/odd-even-linked-list/)

## solution
```c++
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head ||!head->next) return head;
        ListNode *odd= new ListNode (-1), *a = odd, *even = new ListNode(-1), *b = even;
        ListNode * p = head;
        while(p ){
            odd->next = p;
            odd=odd->next;
            p=p->next;
            if(p){
                even->next = p;
                p=p->next;
                even = even->next;
            }    
        }
        even->next = nullptr;
        odd->next = b->next;
        return a->next;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
