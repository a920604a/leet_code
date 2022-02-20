---
title: 25. Reverse Nodes in k-Group
tags:  
    - Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/reverse-nodes-in-k-group/)


## solution
#### option 1 - recursive
```c++
class Solution {
public:
    ListNode* reverse(ListNode * left, ListNode *right){
        ListNode * pre = new ListNode(-1);
        pre->next = left;
        ListNode * cur = left;
        while(cur->next!=right){
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return pre->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // recursive
        ListNode *a = head, *b = head;
        for(int i=0;i<k;++i){
            // 鏈接串列長度不足k個
            if(!b) return head;
            b= b->next;
        }
        ListNode *newhead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newhead;
    }
};
```

#### option 2 - iterative
```c++
class Solution {
public:
    int getsize(ListNode *p){
        int i=0;
        for(i=0;p;p=p->next, i++);
        return i;
    }
    ListNode* getTailNode(ListNode *head, int k){
        ListNode *p = head;
        for(int i=0;i<k;++i){
            if(!p) return head;
            p=p->next;
            
        }
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int size = getsize(head);
        int revertimes = size/k;
        ListNode *cur= head, *b = cur;
        ListNode *ans= new ListNode(-1), *pre = ans;
        pre->next = cur;
        // 要反轉 reversetime 次
        while(revertimes--){
            // reverse node [cur,nextHead)
            ListNode *nextHead = getTailNode(cur,k);
            while(cur->next!=nextHead){
                ListNode * temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            // update the next term head and tail node
            pre = cur;
            cur= nextHead;
        }
        return ans->next;
        
    }
};
```
## analysis
- option 1 - recursive
    - time complexity `O(n)`
    - speed complexity `O(n)` function call
- option 2 - iterative
    - time complexity `O(n)`
    - speed complexity `O(1)`

