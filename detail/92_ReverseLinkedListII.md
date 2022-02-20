---
title: 92. Reverse Linked List II
tags:  
    - Linked List
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/reverse-linked-list-ii/)

## solution

```c++
class Solution {
public:
    ListNode* reverse(ListNode * l, int r){
        ListNode *pre = new ListNode(-1);
        pre->next = l;
        for(int i=0;i<r;++i){
            ListNode *temp = l->next;
            l->next = temp->next;
            temp->next= pre->next;
            pre->next = temp;
        }
        return pre->next;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left ==1){
            return reverse(head, right-1);
        }
        else{
            head->next = reverseBetween(head->next, left-1, right-1);
        }
        return head;
    }
};

```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`