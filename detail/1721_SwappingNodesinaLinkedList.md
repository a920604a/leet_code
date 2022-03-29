---
title: 1721. Swapping Nodes in a Linked List
tags:
    - Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)


## solution

#### option 1 - 複寫值
```c++
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        for(ListNode *p = head;p;p=p->next) size++;
        int a = k, b = size-k;
        ListNode *l = head, *r = head;
        while(--a) l=l->next;
        while(b--) r = r->next;
        int temp = l->val;
        l->val = r->val;
        r->val = temp;
        return head;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(1)`
