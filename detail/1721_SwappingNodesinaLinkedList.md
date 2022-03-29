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
#### option 2 - 交換節點
```c++
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int size = 0;
        for(ListNode *p = head;p;p=p->next) size++;
        int a = k, b = size-k;
        ListNode *l = head , *r = head ;
        ListNode *pl = new ListNode(-1), *pr = pl, *ans = pl; 
        pl->next = head;
        a--;
        int la = min(a, b);
        int lb = max(a,b);
        while(la--) {
            pl = l;
            l=l->next;
        }
        while(lb--) {
            pr = r;
            r = r->next;
        }
        // edge case
        if(l->next ==r ){
            // pr == l
            l->next = r->next;
            pl->next = r;
            r->next = l;
            
            return ans->next;    
        }
        
        ListNode *rlast = nullptr;
        if(r->next) rlast = r->next;
        r->next= l->next;
        l->next = rlast;
        pl->next = r;
        pr->next = l;
        return ans->next;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`
